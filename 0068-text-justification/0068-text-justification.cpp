class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> ans;

        int n = words.size();
        int i = 0;

        while (i < n) {

            int j = i;
            int letters = 0;

            // Find words that fit in this line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {

                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            int spaces = maxWidth - letters;

            string line;

            // Last line OR only one word
            if (j == n || gaps == 0) {

                for (int k = i; k < j; k++) {

                    if (k > i)
                        line += ' ';

                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            }

            // Fully justify
            else {

                int each = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {

                    if (k > i) {

                        line += string(each +
                                      (k - i <= extra ? 1 : 0), ' ');
                    }

                    line += words[k];
                }
            }

            ans.push_back(line);

            i = j;
        }

        return ans;
    }
};