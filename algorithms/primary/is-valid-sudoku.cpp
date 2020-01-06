// 有效数独
/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

说明:
一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。
*/

// 使用哈希表实现
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int SIZE = (int)board.size();
        const int BLOCK_SIZE = 3;

        for (int i = 0; i < SIZE; i++) {
            // 测试行是否满足
            unordered_map<char, int> line;

            for (int j = 0; j < SIZE; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (!line[c]) line[c] = 1;
                else return false;
            }
        }

        for (int i = 0; i < SIZE; i++) {
            // 测试列是否满足

            unordered_map<char, int> column;

            for (int j = 0; j < SIZE; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                if (!column[c]) column[c] = 1;
                else return false;
            }
        }


        // row block num
        for (int i = 0; i < SIZE/BLOCK_SIZE; i++) {
            // col block
            for (int j = 0; j < SIZE/BLOCK_SIZE; j++) {
                unordered_map<char, int> block;

                // small row num
                for (int k = 0; k < BLOCK_SIZE; k++) {
                    // small col num
                    for (int l = 0; l < BLOCK_SIZE; l++) {
                        char c = board[i * BLOCK_SIZE + k][j * BLOCK_SIZE + l];
                        // cout << "(" << i << ", " << j << ", " << k << ", " << l << "): " << c << endl;
                        if (c == '.') continue;
                        if (!block[c]) block[c] = 1;
                        else return false;
                    }
                }
            }
        }

        return true;
    }
};

// to be continued: using xor
