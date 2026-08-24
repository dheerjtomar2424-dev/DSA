class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size()!=t.size()){
            return false;
        }

        int map1[256]={0};
        int map2[256]={0};
        for(int i=0;i<s.size();i++){
            if (map1[s[i]]!=map2[t[i]]){
                return false;
            }
            map1[s[i]]=i+1;
            map2[t[i]]=i+1;
        }  

        return true;
    }
};