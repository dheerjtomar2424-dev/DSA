class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            int distinctCount = 0;
            int freq[105] = {0}; 
            
            for (int j = i; j < n; j++) {
                if (freq[nums[j]] == 0) { 
                    distinctCount++;
                }
                freq[nums[j]]++;
                
                totalSum += distinctCount * distinctCount;
            }
        }
        
        return totalSum;
    }
};