class Solution {
public:

    int solve(int n, int row, int columns, int diag1, int diag2) {

        if (row == n)
            return 1;

        int count = 0;

        int available = ((1 << n) - 1) &
                        ~(columns | diag1 | diag2);

        while (available) {

            int bit = available & -available;
            available -= bit;

            count += solve(
                n,
                row + 1,
                columns | bit,
                (diag1 | bit) << 1,
                (diag2 | bit) >> 1
            );
        }

        return count;
    }

    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }
};