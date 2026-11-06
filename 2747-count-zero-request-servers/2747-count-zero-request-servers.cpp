class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        vector<pair<int, int>> indexedQueries(m);
        for (int i = 0; i < m; ++i) {
            indexedQueries[i] = {queries[i], i};
        }
        sort(indexedQueries.begin(), indexedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> count(n + 1, 0);
        int activeServers = 0;
        int left = 0, right = 0;
        int l = logs.size();

        for (int i = 0; i < m; ++i) {
            int qTime = indexedQueries[i].first;
            int qIdx = indexedQueries[i].second;
            int startTime = qTime - x;

            while (right < l && logs[right][1] <= qTime) {
                if (count[logs[right][0]] == 0) {
                    activeServers++;
                }
                count[logs[right][0]]++;
                right++;
            }

            while (left < l && logs[left][1] < startTime) {
                count[logs[left][0]]--;
                if (count[logs[left][0]] == 0) {
                    activeServers--;
                }
                left++;
            }

            ans[qIdx] = n - activeServers;
        }

        return ans;
    }
};