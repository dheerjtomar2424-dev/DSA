class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        int ml = 1;
        for (int x : nums) {
            ml = lcm(ml, x);
        }

        long long limit = 1LL * ml * mx;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int g = 0, l = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                if (product > limit)
                    break;

                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (product == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
