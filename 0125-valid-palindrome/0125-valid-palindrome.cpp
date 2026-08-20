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

        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};