class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (string &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();

                if (s == "+") st.push_back(a + b);
                else if (s == "-") st.push_back(a - b);
                else if (s == "*") st.push_back(a * b);
                else st.push_back(a / b);
            } 
            else {
                st.push_back(stoi(s));
            }
        }

        return st.back();
    }
};