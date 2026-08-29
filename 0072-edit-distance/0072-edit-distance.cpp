class Solution {
public:
    int minDistance(string word1, string word2) {

        // Use the shorter string for DP to reduce memory
        if (word1.size() < word2.size())
            swap(word1, word2);

        int m = word1.size();
        int n = word2.size();

        vector<int> dp(n + 1);

        // Convert empty string to word2
        for (int j = 0; j <= n; j++)
            dp[j] = j;

        for (int i = 1; i <= m; i++) {

            int prev = dp[0];
            dp[0] = i;

            for (int j = 1; j <= n; j++) {

                int temp = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                }
                else {
                    dp[j] = 1 + min({
                        prev,      // replace
                        dp[j],     // delete
                        dp[j - 1]  // insert
                    });
                }

                prev = temp;
            }
        }

        return dp[n];
    }
};