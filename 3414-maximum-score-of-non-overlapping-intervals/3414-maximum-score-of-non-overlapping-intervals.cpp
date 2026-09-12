#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort primarily by right endpoint. If right endpoints match, sort by left endpoint, then by original index
        sort(a.begin(), a.end(), [](const Interval& x, const Interval& y) {
            if (x.r != y.r) return x.r < y.r;
            if (x.l != y.l) return x.l < y.l;
            return x.id < y.id;
        });

        // dp[k][i] stores: { -total_weight, lexicographically_sorted_original_indices }
        // k in [0..4], i in [0..n]
        using State = pair<long long, vector<int>>;
        vector<vector<State>> dp(5, vector<State>(n + 1, {0, {}}));

        // Precompute right endpoints for binary search
        vector<int> r_vals(n);
        for (int i = 0; i < n; ++i) {
            r_vals[i] = a[i].r;
        }

        for (int i = 1; i <= n; ++i) {
            // Find the latest interval j that does not overlap with a[i - 1]:
            // Non-overlapping condition: a[j - 1].r < a[i - 1].l
            int prev_idx = lower_bound(r_vals.begin(), r_vals.begin() + i - 1, a[i - 1].l) - r_vals.begin();

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Do not pick the current interval
                State best = dp[k][i - 1];

                // Option 2: Pick the current interval
                const State& prev_state = dp[k - 1][prev_idx];
                long long new_neg_wt = prev_state.first - a[i - 1].weight;
                
                vector<int> new_ids = prev_state.second;
                // Insert original id while keeping the index list sorted
                new_ids.insert(lower_bound(new_ids.begin(), new_ids.end(), a[i - 1].id), a[i - 1].id);

                State take_state = {new_neg_wt, move(new_ids)};

                // Take the minimal State: largest weight, tie-break by lexicographically smallest indices
                if (best.first == 0 && best.second.empty()) {
                    best = move(take_state);
                } else if (take_state < best) {
                    best = move(take_state);
                }

                dp[k][i] = move(best);
            }
        }

        // Find the best choice across choosing 1, 2, 3, or 4 intervals
        State best_overall = {0, {}};
        for (int k = 1; k <= 4; ++k) {
            if (dp[k][n].first != 0 || !dp[k][n].second.empty()) {
                if (best_overall.first == 0 && best_overall.second.empty()) {
                    best_overall = dp[k][n];
                } else if (dp[k][n] < best_overall) {
                    best_overall = dp[k][n];
                }
            }
        }

        return best_overall.second;
    }
};