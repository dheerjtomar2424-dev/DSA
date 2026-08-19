class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int flag = 0;
            for(int j=0;j<nums.size();j++){
                if ((nums[i]+nums[j]==target && j!=i) ){

                    ans.push_back(i);
                    ans.push_back(j);
                    flag=1;
                    break;

                }
            }
            if (flag==1){
                break;
            }
        }
    return ans;       
    }
};