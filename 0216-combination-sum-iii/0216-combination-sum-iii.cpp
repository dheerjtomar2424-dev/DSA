class Solution {
    vector<vector<int>> ans;
    vector<int> cur;

    void dfs(int start, int k, int target) {
        if (k == 0) {
            if (target == 0)
                ans.push_back(cur);
            return;
        }

        if (target <= 0)
            return;

        for (int i = start; i <= 9; ++i) {
            if (i > target)
                break;

            cur.push_back(i);
            dfs(i + 1, k - 1, target - i);
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};