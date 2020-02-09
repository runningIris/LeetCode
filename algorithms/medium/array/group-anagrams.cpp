/**
字谜分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> flag;
        unordered_map<string, vector<string>> container;

        for (string str: strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            if (flag[copy] != 1) {
                flag[copy] = 1;
                container[copy] = vector<string>({str});
            } else {
                container[copy].push_back(str);
            }
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = container.begin(); it != container.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};
