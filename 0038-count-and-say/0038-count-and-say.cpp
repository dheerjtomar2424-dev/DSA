class Solution {
public:
    string countAndSay(int n) {

        string s = "1";

        for (int k = 1; k < n; k++) {

            string next = "";

            for (int i = 0; i < s.size(); ) {

                int j = i;

                while (j < s.size() && s[j] == s[i]) {
                    j++;
                }

                next += to_string(j - i);
                next += s[i];

                i = j;
            }

            s = next;
        }

        return s;
    }
};