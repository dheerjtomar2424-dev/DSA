class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        int i=0,temp;

       while(n>0){

        temp=nums[n];
        nums.erase(nums.begin() + n);
        nums.push_back(nums[i]);
        nums.erase(nums.begin());
        nums.push_back(temp);
        
        n--;

       }

        return nums;
        
    }
};