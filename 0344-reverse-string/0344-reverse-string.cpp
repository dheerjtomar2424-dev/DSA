class Solution {
public:
    void reverseString(vector<char>& s) {

        for(int i=0;i<s.size();i++){
            if (i<s.size()-1-i){
                char temp = s[i];
                s[i]=s[s.size()-1-i];
                s[s.size()-1-i]=temp;
            }
        }  
    }
};