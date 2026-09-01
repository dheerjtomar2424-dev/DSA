class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<bool>> isPal;

    void dfs(const string& s, int start) {

        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            if (!isPal[start][end])
                continue;

            path.push_back(s.substr(start, end - start + 1));

            dfs(s, end + 1);

            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.size();

        isPal.assign(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i < 2 || isPal[i + 1][j - 1])) {

                    isPal[i][j] = true;
                }
            }
        }

        dfs(s, 0);

        return ans;
    }
};