class Solution {
private:
    void f(int r, int c, vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || g[r][c] == 1) return;
        g[r][c] = 1;
        f(r + 1, c, g);
        f(r - 1, c, g);
        f(r, c + 1, g);
        f(r, c - 1, g);
    }
public:
    int closedIsland(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        for (int c = 0; c < n; ++c) {
            if (g[0][c] == 0) f(0, c, g);
            if (g[m - 1][c] == 0) f(m - 1, c, g);
        }
        for (int r = 0; r < m; ++r) {
            if (g[r][0] == 0) f(r, 0, g);
            if (g[r][n - 1] == 0) f(r, n - 1, g);
        }
        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (g[r][c] == 0) {
                    ans++;
                    f(r, c, g);
                }
            }
        }
        return ans;
    }
};