class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long last = 0;
        long long result = 0;
        char op = '+';

        for (int i = 0; i <= s.size(); ++i) {
            char c = (i < s.size() ? s[i] : '+');

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                continue;
            }

            if (c == ' ') continue;

            if (op == '+') {
                result += last;
                last = num;
            }
            else if (op == '-') {
                result += last;
                last = -num;
            }
            else if (op == '*') {
                last *= num;
            }
            else if (op == '/') {
                last /= num;
            }

            op = c;
            num = 0;
        }

        return result + last;
    }
};