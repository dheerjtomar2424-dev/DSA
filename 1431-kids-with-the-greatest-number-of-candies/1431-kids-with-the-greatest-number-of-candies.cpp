class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        for(int i = 0; i <candies.size();i++){
            int sum = candies[i] + extraCandies;
            bool check = true;
            for(int j = 0; j <candies.size();j++){
                
                if (sum<candies[j]){
                    check = false;
                    break;
                }

            }
            result[i]= check;
        }
        return result;
    }
};