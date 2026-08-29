class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string& s1, string& s2, int i, int j, int len) {

        string key = to_string(i) + "," +
                     to_string(j) + "," +
                     to_string(len);

        if (memo.count(key))
            return memo[key];

        // Same substring
        if (s1.compare(i, len, s2, j, len) == 0)
            return memo[key] = true;

        // Character frequency pruning
        int count[26] = {};

        for (int k = 0; k < len; k++) {
            count[s1[i + k] - 'a']++;
            count[s2[j + k] - 'a']--;
        }

        for (int x : count) {
            if (x != 0)
                return memo[key] = false;
        }

        // Try every possible split
        for (int k = 1; k < len; k++) {

            // No swap
            if (solve(s1, s2, i, j, k) &&
                solve(s1, s2, i + k, j + k, len - k)) {
                return memo[key] = true;
            }

            // Swap
            if (solve(s1, s2, i, j + len - k, k) &&
                solve(s1, s2, i + k, j, len - k)) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size())
            return false;

        return solve(s1, s2, 0, 0, s1.size());
    }
};