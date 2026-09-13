class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect positions of all 1s
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j]) ones1.emplace_back(i, j);
                if (img2[i][j]) ones2.emplace_back(i, j);
            }
        }

        // Shift range is [-(n - 1), n - 1], mapped to [0, 2n - 1]
        // Flattened 2D offset table of size (2n) * (2n)
        int shiftCount[60][60] = {0};
        int maxOverlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r2 - r1 + n;
                int dc = c2 - c1 + n;
                shiftCount[dr][dc]++;
                if (shiftCount[dr][dc] > maxOverlap) {
                    maxOverlap = shiftCount[dr][dc];
                }
            }
        }

        return maxOverlap;
    }
};