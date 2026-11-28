class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> cnt(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int j = f; j <= n; j += f) {
                cnt[f] += freq[j];
            }
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long remaining = budget;
        long long ans = 0;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (2LL * minPrice <= price) {
                break;
            }

            int freeCount = cnt[factor] - 1;

            long long take = min(
                (long long)freeCount,
                remaining / price
            );

            ans += 2LL * take;
            remaining -= take * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};
