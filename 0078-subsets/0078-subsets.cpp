class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int index, vector<int>& nums) {

        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            current.push_back(nums[i]);

            backtrack(i + 1, nums);

            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        backtrack(0, nums);

        return ans;
    }
};