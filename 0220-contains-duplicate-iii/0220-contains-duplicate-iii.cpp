class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (indexDiff <= 0 || valueDiff < 0)
            return false;

        set<long long> window;

        for (int i = 0; i < nums.size(); ++i) {
            long long x = nums[i];

            // Find the smallest value >= x - valueDiff
            auto it = window.lower_bound(x - valueDiff);

            if (it != window.end() && *it <= x + valueDiff)
                return true;

            window.insert(x);

            // Keep only indexDiff previous elements
            if (i >= indexDiff)
                window.erase(nums[i - indexDiff]);
        }

        return false;
    }
};