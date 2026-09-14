class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Fast I/O for 0ms execution
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> ans(n, 1);

        // Compute prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Multiply suffix products directly in-place
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};