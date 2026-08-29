class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(int start, int n, int k) {

        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Number of elements still needed
        int need = k - current.size();

        // Pruning: ensure enough numbers remain
        for (int i = start; i <= n - need + 1; i++) {

            current.push_back(i);

            backtrack(i + 1, n, k);

            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        backtrack(1, n, k);

        return ans;
    }
};