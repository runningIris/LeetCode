// 旋转图像

// 给定一个 n × n 的二维矩阵表示一个图像。将图像顺时针旋转 90 度。
// 说明：你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

// 关键点：交换形成一个圈
// Example:
// M1: (1, 2)
// M2: (2, 4) = (2, 5 - 1)
// M3: (4, 3) = (5 - 1, 5 - 2)
// M4: (3, 1) = (5 - 2, 1)

// M4 = M3
// M3 = M2
// M2 = M1
// M1 = M4
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int size = (int)matrix.size();
        int max = size - 1;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size - i; j++) {
                int m1 = matrix[i][j];
                int m2 = matrix[j][max - i];
                int m3 = matrix[max - i][max - j];
                int m4 = matrix[max - j][i];

                matrix[max - j][i] = m3;
                matrix[max - i][max - j] = m2;
                matrix[j][max - i] = m1;
                matrix[i][j] = m4;
            }
        }
    }
};
