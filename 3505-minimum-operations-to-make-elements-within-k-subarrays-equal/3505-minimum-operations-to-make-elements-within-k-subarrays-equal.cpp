class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                high.insert(val);

                sumLow -= val;
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();
                high.erase(high.begin());
                low.insert(val);

                sumHigh -= val;
                sumLow += val;
            }
        };

        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            if (i >= x) {
                int out = nums[i - x];

                auto it = low.find(out);

                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= out;
                } else {
                    it = high.find(out);
                    high.erase(it);
                    sumHigh -= out;
                }
            }

            balance();

            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long operations =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();

                cost.push_back(operations);
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int t = 0; t <= k; t++) {
            for (int i = 0; i <= n; i++) {
                if (dp[t][i] == INF)
                    continue;

                if (i < n) {
                    dp[t][i + 1] = min(
                        dp[t][i + 1], dp[t][i]
                    );
                }

                if (t < k && i + x <= n) {
                    dp[t + 1][i + x] = min(
                        dp[t + 1][i + x],
                        dp[t][i] + cost[i]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
