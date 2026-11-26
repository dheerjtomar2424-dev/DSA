class Solution {
public:
    bool canAliceWin(int n) { 

        int check =0;
        for(int i=10;i>=1;i--){
            if(check%2!=0 && n<i){
                return true;
            }
            else if (check%2==0 && n<i){
                return false;
            }
            else {
                check++;
                n=n-i;
            }
        }        
    return 0;  
    }
};