class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    void solve(int row, int n, int columns, int diag1, int diag2) {

        if (row == n) {
            ans.push_back(board);
            return;
        }

        int available = ((1 << n) - 1) & ~(columns | diag1 | diag2);

        while (available) {

            int bit = available & -available;
            available -= bit;

            int col = __builtin_ctz(bit);

            board[row][col] = 'Q';

            solve(
                row + 1,
                n,
                columns | bit,
                (diag1 | bit) << 1,
                (diag2 | bit) >> 1
            );

            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        board = vector<string>(n, string(n, '.'));

        solve(0, n, 0, 0, 0);

        return ans;
    }
};