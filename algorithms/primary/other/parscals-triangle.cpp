/**
帕斯卡三角形
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
      1
     1,1
    1,2,1
   1,3,3,1
  1,4,6,4,1
 1,5,10,10,5,1
1,6,15,20,15,6,1
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            row.push_back(1);

            if (i == 0) {
                result.push_back(row);
                continue;
            }

            // 注意 j < i - 1
            for (int j = 0; j < i - 1; j++) {
                row.push_back(result[i-1][j] + result[i-1][j+1]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};
