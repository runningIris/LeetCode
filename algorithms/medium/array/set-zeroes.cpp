/**
矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
*/

// 需要额外的空间来存放需要置零的行列
// 时间 O(m*n), 空间 O(m+n)
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

// 如果 matrix[m][n] 是 0, 则把行首和列首标志为 0, 这样不需要额外的空间来存储需要置零的行和列
// 时间 O(m*n), 空间 O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize = (int)matrix.size();
        int colSize = (int)matrix[0].size();
        bool isCol = false;
        for (int i = 0; i < rowSize; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }

            for (int j = 1; j < colSize; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < rowSize; i++) {
            for (int j = 1; j < colSize; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < colSize; j++) {
                matrix[0][j] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < rowSize; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
