class Solution {
    int n_nodes;
    vector<vector<int>> adj;
    vector<int> heavy, parent, depth, pos;
    int timer;
    vector<int> tree;

    int dfs_sz(int u, int p) {
        int sz = 1;
        int max_sz = 0;
        heavy[u] = -1;
        for (int v : adj[u]) {
            if (v != p) {
                int sub_sz = dfs_sz(v, u);
                sz += sub_sz;
                if (sub_sz > max_sz) {
                    max_sz = sub_sz;
                    heavy[u] = v;
                }
            }
        }
        return sz;
    }

    void dfs_hld(int u, int h, vector<int>& head) {
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1) {
            dfs_hld(heavy[u], h, head);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs_hld(v, v, head);
            }
        }
    }

    void build_tree(int node, int start, int end, const string& s, const vector<int>& inv_pos) {
        if (start == end) {
            tree[node] = (1 << (s[inv_pos[start]] - 'a'));
            return;
        }
        int mid = (start + end) / 2;
        build_tree(2 * node, start, mid, s, inv_pos);
        build_tree(2 * node + 1, mid + 1, end, s, inv_pos);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update_tree(2 * node, start, mid, idx, val);
        else update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v, const vector<int>& head) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res ^= query_tree(1, 1, n_nodes, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= query_tree(1, 1, n_nodes, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n_nodes = n;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        heavy.assign(n, -1);
        parent.assign(n, 0);
        depth.assign(n, 0);
        pos.assign(n, 0);
        vector<int> head(n, 0);
        timer = 0;

        auto get_depth_and_parent = [&](auto& self, int u, int p, int d) -> void {
            depth[u] = d;
            parent[u] = p;
            for (int v : adj[u]) {
                if (v != p) {
                    self(self, v, u, d + 1);
                }
            }
        };
        get_depth_and_parent(get_depth_and_parent, 0, -1, 0);

        dfs_sz(0, -1);
        dfs_hld(0, 0, head);

        vector<int> inv_pos(n + 1);
        for (int i = 0; i < n; ++i) {
            inv_pos[pos[i]] = i;
        }

        tree.assign(4 * n + 1, 0);
        build_tree(1, 1, n, s, inv_pos);

        vector<bool> ans;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();
                update_tree(1, 1, n, pos[u], 1 << (c - 'a'));
            } else {
                int space1 = q.find(' ', 6);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));
                int mask = query_path(u, v, head);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};