class Solution {
    static constexpr int MOD = 1e9 + 7;
    
    vector<long long> sumSq, sumV, lazy;

    void build(int node, int l, int r) {
        if (l == r) {
            sumSq[node] = 0;
            sumV[node] = 0;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        sumV[node] = (sumV[2 * node] + sumV[2 * node + 1]) % MOD;
    }

    void apply(int node, int l, int r, long long val) {
        // (c + val)^2 = c^2 + 2*val*c + val^2 * (r - l + 1)
        long long len = (r - l + 1);
        sumSq[node] = (sumSq[node] + 2 * val * sumV[node] + val * val * len) % MOD;
        sumV[node] = (sumV[node] + val * len) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            int mid = l + (r - l) / 2;
            apply(2 * node, l, mid, lazy[node]);
            apply(2 * node + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        sumSq[node] = (sumSq[2 * node] + sumSq[2 * node + 1]) % MOD;
        sumV[node] = (sumV[2 * node] + sumV[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sumSq.assign(4 * n, 0);
        sumV.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        build(1, 0, n - 1);
        unordered_map<int, int> last_pos;
        long long total_sum = 0;
        long long current_ans = 0;

        for (int j = 0; j < n; ++j) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            last_pos[nums[j]] = j;

            // Update segment tree for range [prev + 1, j]
            update(1, 0, n - 1, prev + 1, j, 1);
            
            // sumSq[1] now holds the sum of squares of distinct counts for all subarrays ending at j
            current_ans = (current_ans + sumSq[1]) % MOD;
        }

        return current_ans;
    }
};