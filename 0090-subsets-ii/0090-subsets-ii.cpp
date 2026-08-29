class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void backtrack(vector<int>& nums, int start) {

        ans.push_back(cur);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            cur.push_back(nums[i]);

            backtrack(nums, i + 1);

            cur.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        backtrack(nums, 0);

        return ans;
    }
};