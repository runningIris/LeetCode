/**
矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = (int)matrix.size();
        int colSize = (int)matrix[0].size();
        int rows[rowSize] = {0};
        int cols[colSize] = {0};
        // 找到所有 0 所在的行和列
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        // 统一设置行为 0
        for (int i = 0; i < rowSize; i++) {
            if (rows[i] == 1) {
                for (int j = 0; j < colSize; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 统一设置列为 0
        for (int i = 0; i < colSize; i++) {
            if (cols[i] == 1) {
                for (int j = 0; j < rowSize; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
