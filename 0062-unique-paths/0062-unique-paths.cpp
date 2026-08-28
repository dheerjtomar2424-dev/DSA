class Solution {
public:
    int uniquePaths(int m, int n) {

        long long ans = 1;

        int total = m + n - 2;
        int down = min(m - 1, n - 1);

        for (int i = 1; i <= down; i++) {
            ans = ans * (total - down + i) / i;
        }

        return ans;
    }
};