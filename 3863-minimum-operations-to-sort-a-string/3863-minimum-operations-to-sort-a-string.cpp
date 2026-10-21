class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(),s.end())) return 0;
        if (n==2) return -1;

        int min = *min_element(s.begin(),s.end());
        int max = *max_element(s.begin(),s.end());

        if (min==s[0] || max==s[n-1]) return 1;

        for (int i=1;i<n-1;i++){
            if (min==s[i] || max==s[i]) return 2; 
        }

        // if min==s[n-1] && max==s[0]
        return 3;
    }
};