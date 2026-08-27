class Solution {
public:
    int longestValidParentheses(string s) {

        int left = 0, right = 0;
        int ans = 0;

        // Left to right
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                ans = max(ans, 2 * right);
            }
            else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        // Right to left
        left = 0;
        right = 0;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                ans = max(ans, 2 * left);
            }
            else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return ans;
    }
};