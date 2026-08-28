class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int start) {

        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        bool used[21] = {};

        for (int i = start; i < nums.size(); i++) {

            if (used[nums[i] + 10])
                continue;

            used[nums[i] + 10] = true;

            swap(nums[start], nums[i]);

            solve(nums, start + 1);

            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        solve(nums, 0);

        return ans;
    }
};