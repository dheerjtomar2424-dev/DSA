class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> total_ans(k, 0);
        // dp[r] represents the number of subarrays ending at the previous element with product % k == r
        long long dp[5] = {0};

        for (int num : nums) {
            long long next_dp[5] = {0};
            int val = num % k;

            // Single-element subarray starting and ending at current index
            next_dp[val]++;

            // Extend previous subarrays
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    next_dp[(r * val) % k] += dp[r];
                }
            }

            // Accumulate counts into total_ans and update dp
            for (int r = 0; r < k; ++r) {
                total_ans[r] += next_dp[r];
                dp[r] = next_dp[r];
            }
        }

        return total_ans;
    }
};