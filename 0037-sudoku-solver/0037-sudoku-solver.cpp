class Solution {
public:
    int row[9] = {};
    int col[9] = {};
    int box[9] = {};

    bool solve(vector<vector<char>>& board) {

        int bestR = -1, bestC = -1;
        int bestMask = 0;
        int minCount = 10;

        // Find the empty cell with the fewest possibilities
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] != '.')
                    continue;

                int b = (r / 3) * 3 + (c / 3);

                int used = row[r] | col[c] | box[b];
                int mask = (~used) & 0x1FF;

                int count = __builtin_popcount(mask);

                if (count < minCount) {
                    minCount = count;
                    bestR = r;
                    bestC = c;
                    bestMask = mask;
                }
            }
        }

        // No empty cell → solved
        if (bestR == -1)
            return true;

        int b = (bestR / 3) * 3 + (bestC / 3);

        while (bestMask) {

            // Get lowest available bit
            int bit = bestMask & -bestMask;
            bestMask -= bit;

            int num = __builtin_ctz(bit);

            board[bestR][bestC] = '1' + num;

            row[bestR] |= bit;
            col[bestC] |= bit;
            box[b] |= bit;

            if (solve(board))
                return true;

            // Undo
            row[bestR] ^= bit;
            col[bestC] ^= bit;
            box[b] ^= bit;

            board[bestR][bestC] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        // Initialize masks
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.')
                    continue;

                int bit = 1 << (board[r][c] - '1');
                int b = (r / 3) * 3 + (c / 3);

                row[r] |= bit;
                col[c] |= bit;
                box[b] |= bit;
            }
        }

        solve(board);
    }
};