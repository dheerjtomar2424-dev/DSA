class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, pair<int, int>>> events;

        for (auto &b : buildings) {
            // start: negative height
            events.push_back({b[0], {-b[2], b[1]}});
            // end: positive height
            events.push_back({b[1], {b[2], b[1]}});
        }

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> pq;
        pq.push({0, INT_MAX});

        vector<vector<int>> ans;
        int prevHeight = 0;

        for (auto &e : events) {
            int x = e.first;
            int h = e.second.first;
            int end = e.second.second;

            if (h < 0) {
                pq.push({-h, end});
            } else {
                // Lazy deletion: remove expired buildings
                while (!pq.empty() && pq.top().second <= x)
                    pq.pop();

                // Marking an end is handled by expiration checks
                // at the top of the heap.
            }

            while (!pq.empty() && pq.top().second <= x)
                pq.pop();

            int curHeight = pq.top().first;

            if (curHeight != prevHeight) {
                ans.push_back({x, curHeight});
                prevHeight = curHeight;
            }
        }

        return ans;
    }
};