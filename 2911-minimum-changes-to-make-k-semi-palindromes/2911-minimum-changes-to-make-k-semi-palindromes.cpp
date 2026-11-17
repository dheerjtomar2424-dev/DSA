class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> factors(n + 1);
        for (int d = 1; d < n; d++) {
            for (int i = d * 2; i <= n; i += d) {
                factors[i].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                int best = n;

                for (int d : factors[len]) {
                    int cnt = 0;

                    for (int x = 0; x < d; x++) {
                        int l = i + x;
                        int r = j - d + 1 + x;

                        while (l < r) {
                            if (s[l] != s[r]) cnt++;
                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, cnt);
                }

                cost[i][j] = best;
            }
        }

        const int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int h = 0; h <= i - 2; h++) {
                    if (dp[h][j - 1] == INF) continue;

                    dp[i][j] = min(dp[i][j],
                        dp[h][j - 1] + cost[h][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
