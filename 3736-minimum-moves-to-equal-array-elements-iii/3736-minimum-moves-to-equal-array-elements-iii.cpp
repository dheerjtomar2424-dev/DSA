class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        return maxi * nums.size() - accumulate(nums.begin(), nums.end(), 0);
    }
};