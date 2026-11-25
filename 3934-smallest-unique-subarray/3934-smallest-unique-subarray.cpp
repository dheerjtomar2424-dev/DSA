class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        iota(sa.begin(), sa.end(), 0);

        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(values.begin(), values.end(), nums[i])
                      - values.begin();
        }

        for (int len = 1; len < n; len *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = a + len < n ? rank[a + len] : -1;
                int y = b + len < n ? rank[b + len] : -1;

                return x < y;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                int a1 = rank[a];
                int b1 = rank[b];

                int a2 = a + len < n ? rank[a + len] : -1;
                int b2 = b + len < n ? rank[b + len] : -1;

                temp[b] = temp[a] + (a1 != b1 || a2 != b2);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;

            if (h > 0)
                h--;
        }

        int ans = n;

        for (int r = 0; r < n; r++) {
            int left = lcp[r];
            int right = (r + 1 < n) ? lcp[r + 1] : 0;

            int need = max(left, right) + 1;

            if (need <= n - sa[r]) {
                ans = min(ans, need);
            }
        }

        return ans;
    }
};
