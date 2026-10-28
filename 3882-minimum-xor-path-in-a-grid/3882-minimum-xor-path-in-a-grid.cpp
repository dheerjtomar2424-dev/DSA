#include <vector>
#include <unordered_set>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::unordered_set<int>> dp(n);
        dp[0].insert(grid[0][0]);
        
        for (int j = 1; j < n; ++j) {
            for (int val : dp[j - 1]) {
                dp[j].insert(val ^ grid[0][j]);
            }
        }
        
        for (int i = 1; i < m; ++i) {
            std::unordered_set<int> new_cell;
            for (int val : dp[0]) {
                new_cell.insert(val ^ grid[i][0]);
            }
            dp[0] = std::move(new_cell);
            
            for (int j = 1; j < n; ++j) {
                std::unordered_set<int> current_cell;
                for (int val : dp[j - 1]) {
                    current_cell.insert(val ^ grid[i][j]);
                }
                for (int val : dp[j]) {
                    current_cell.insert(val ^ grid[i][j]);
                }
                dp[j] = std::move(current_cell);
            }
        }
        
        int min_val = 1024;
        for (int val : dp[n - 1]) {
            if (val < min_val) {
                min_val = val;
            }
        }
        
        return min_val;
    }
};