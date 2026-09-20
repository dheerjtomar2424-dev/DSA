class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < s.length(); ++i) {
            int rev_alpha = 26 - (s[i] - 'a');
            int string_pos = i + 1;
            total += rev_alpha * string_pos;
        }
        return total;
    }
};