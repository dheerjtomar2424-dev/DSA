class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            
            // Cast to long long to prevent overflow when nums[i] == INT_MAX
            while (i + 1 < n && (long long)nums[i + 1] - nums[i] == 1) {
                i++;
            }
            
            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        
        return result;
    }
};