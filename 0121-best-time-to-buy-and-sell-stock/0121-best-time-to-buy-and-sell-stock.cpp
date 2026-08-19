class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int MaxProfit=0,min=prices[0];

        for (int i=0;i<prices.size();i++){

            if (min > prices[i] ){
                min = prices[i];
            }

            int profit = prices[i]-min;

            if (profit>MaxProfit){
                MaxProfit=profit;
            }

        }

        return MaxProfit;
        
    }
};