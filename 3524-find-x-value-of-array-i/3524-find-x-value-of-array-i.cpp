class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> total_ans(k, 0);
        long long dp[5] = {0};

        for (int num : nums) {
            long long next_dp[5] = {0};
            int val = num % k;

            next_dp[val]++;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * val) % k] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                total_ans[r] += next_dp[r];
                dp[r] = next_dp[r];
            }
        }

        return total_ans;
    }
};