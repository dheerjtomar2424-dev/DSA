class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for (int c = 0; c < 26; ++c) {
            if (first[c] == -1) continue;

            int left = first[c];
            int right = last[c];
            bool valid = true;

            for (int i = left; i <= right; ++i) {
                int cur = s[i] - 'a';
                if (first[cur] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[cur]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Greedy interval scheduling: sort by ending index
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        vector<string> res;
        int prev_end = -1;
        for (const auto& [l, r] : intervals) {
            if (l > prev_end) {
                res.push_back(s.substr(l, r - l + 1));
                prev_end = r;
            }
        }

        return res;
    }
};