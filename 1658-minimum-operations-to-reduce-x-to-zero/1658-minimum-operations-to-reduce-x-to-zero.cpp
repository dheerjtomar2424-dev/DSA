#pragma GCC optimize("O3")

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;

        // Base cases
        if (target == 0) return nums.size();
        if (target < 0) return -1;

        int n = nums.size();
        int currentSum = 0;
        int maxLen = -1;
        int left = 0;

        // Sliding window to find maximum subarray with sum == target
        for (int right = 0; right < n; ++right) {
            currentSum += nums[right];

            while (currentSum > target && left <= right) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : (n - maxLen);
    }
};