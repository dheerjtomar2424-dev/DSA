class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        int i = n - 1;

        while (i >= 0) {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0) break;

            int end = i;

            while (i >= 0 && s[i] != ' ')
                i--;

            if (!ans.empty())
                ans += ' ';

            ans.append(s, i + 1, end - i);
        }

        return ans;
    }
};