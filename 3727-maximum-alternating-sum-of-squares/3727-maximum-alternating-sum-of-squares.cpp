class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int& i : nums){
            i *= i;
        }
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long sum = 0;
        for (int i=0;i<n;i++){

            if (i<n/2){
                sum -= nums[i];
            }
            else {
                sum += nums[i];
            }
        }

    return sum;

        
    }
};