class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target,
               int start, vector<int>& current) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since sorted, no later value can work
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // i + 1 because each element can be used only once
            solve(candidates, target - candidates[i], i + 1, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        solve(candidates, target, 0, current);

        return ans;
    }
};