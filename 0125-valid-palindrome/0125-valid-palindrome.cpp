// class Solution {
// public:
//     bool isPalindrome(string s) {

//         for( int i=0;i<s.size();i++){
//             if (!((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9'))){
//                 s.erase(s.begin()+i);
//                 i--;
//             }
//         }
//         for( int i=0;i<s.size();i++){

//             if(s[i]>='A' && s[i]<='Z'){
//                 s[i]=tolower(s[i]);
//             }
//         }


//          for(int i=0;i<s.size()/2;i++){
//             if ((s[i]!=s[s.size()-1-i])){
//                 return false;
//             }
//         }
//       return true; 

class Solution {
public:
    bool isPalindrome(string s) {

        for (int i=0;i<s.size();i++){
            if (!(isalnum(s[i]))){
                s.erase(s.begin() + i);
                i--;
            }    
        }

        for (int i=0;i<s.size();i++){
            if (tolower(s[i]) != tolower(s[s.size()-i-1])){
                return false;
            }
        
        }


      return true;
    }
};