// 实现 strStr()
// (字符串匹配，KMP 算法)

class Solution {
private:
    vector<int> CreateStatesMachine(string& needle) {
        int i;
        int j = -1;
        int size = (int)needle.size();
        vector<int> states;
        states.push_back(-1);
        for (i = 1; i < size; i++) {
            while (j > -1 && needle[j+1] != needle[i]) {
                j = states[j];
            }
            if (needle[j+1] == needle[i]) {
                j++;
            }
            states.push_back(j);
        }
        return states;
    }

    /*
     aabaaac -> states: -1,0,-1,0,1,1,-1

     i=1, j=-1, j=0; states[1]=0;
     i=2, j=states[0]=-1; states[2]=-1
     i=3, j=0; states[3]=0;
     i=4, j=1; states[4]=1;
     i=5, j=states[1]=0, j=1; states[5]=1
     i=6, j=states[1]=0, j=states[0]=-1; states[6]=-1
     */
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int i = 0, j = 0; // haystack 和 needle 的下标
        int size = (int)haystack.size(), N = (int)needle.size();
        vector<int> states = CreateStatesMachine(needle);

        while (i < size) {
            if (haystack[i] != needle[j]) {
                if (j > 0) {
                    j = states[j - 1] + 1;
                } else {
                    i++;
                }
            } else {
                j++;
                i++;
            }
            if (j == N) return i - j;
        }
        return -1;
    }
};
