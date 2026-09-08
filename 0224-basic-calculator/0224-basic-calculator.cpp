class Solution {
public:
    int calculate(string s) {
        long long result = 0;
        long long num = 0;
        int sign = 1;

        stack<pair<long long, int>> st;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+' || c == '-') {
                result += sign * num;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            }
            else if (c == '(') {
                st.push({result, sign});
                result = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;

                auto [prevResult, prevSign] = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        return result + sign * num;
    }
};