class Solution {
    int m, n;
    bool visited[100][100][101];

    bool dfs(int r, int c, int bal, const std::vector<std::vector<char>>& grid) {
        // Update balance for current cell
        bal += (grid[r][c] == '(' ? 1 : -1);

        // Balance cannot be negative or exceed the max remaining path length
        if (bal < 0 || bal > (m - r + n - c - 1)) {
            return false;
        }

        // Reached bottom-right cell
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        // Return false if state has already been visited
        if (visited[r][c][bal]) {
            return false;
        }
        visited[r][c][bal] = true;

        // Move Down
        if (r + 1 < m && dfs(r + 1, c, bal, grid)) {
            return true;
        }

        // Move Right
        if (c + 1 < n && dfs(r, c + 1, bal, grid)) {
            return true;
        }

        return false;
    }

public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length (m + n - 1) must be even for valid parentheses
        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        // Initialize memoization array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k <= (m + n) / 2; ++k) {
                    visited[i][j][k] = false;
                }
            }
        }

        return dfs(0, 0, 0, grid);
    }
};