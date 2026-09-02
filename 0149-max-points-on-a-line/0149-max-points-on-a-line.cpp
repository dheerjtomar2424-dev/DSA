class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> mp;
            int duplicate = 1;
            int best = 0;

            for (int j = i + 1; j < n; j++) {
                long long dx = points[j][0] - points[i][0];
                long long dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                long long g = gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // Normalize slope
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                // Encode (dy, dx)
                long long key = (dy << 32) ^ (dx & 0xffffffffLL);

                mp[key]++;
                best = max(best, mp[key]);
            }

            ans = max(ans, best + duplicate);
        }

        return ans;
    }
};