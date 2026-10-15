#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        // Outer loop for the starting index
        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctElements;
            
            // Inner loop for the ending index
            for (int j = i; j < n; j++) {
                distinctElements.insert(nums[j]);
                int count = distinctElements.size();
                
                // Add the square of the distinct count to the total sum
                totalSum += count * count;
            }
        }
        
        return totalSum;
    }
};