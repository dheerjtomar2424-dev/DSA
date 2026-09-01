class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        vector<vector<bool>> pal(
            n, vector<bool>(n, false)
        );

        // Precompute palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts for s[0...i]
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {

            // Whole prefix is palindrome
            if (pal[0][i]) {
                dp[i] = 0;
                continue;
            }

            dp[i] = i;

            for (int j = 1; j <= i; j++) {

                if (pal[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};