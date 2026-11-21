class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);
        vector<int> newParent(n, -1), ans(n);
        vector<vector<int>> path(26);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            if (u != 0) {
                if (!path[c].empty())
                    newParent[u] = path[c].back();
                else
                    newParent[u] = parent[u];
            }

            path[c].push_back(u);

            for (int v : adj[u]) {
                dfs(v);
            }

            path[c].pop_back();
        };

        dfs(0);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        function<int(int)> calc = [&](int u) {
            int size = 1;

            for (int v : newAdj[u]) {
                size += calc(v);
            }

            ans[u] = size;
            return size;
        };

        calc(0);

        return ans;
    }
};
