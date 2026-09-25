class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> resultSet = parse(expression, i);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> parse(const string& expr, int& i) {
        set<string> unionSet;        // Stores the union of terms separated by ','
        vector<set<string>> concatStack; // Stores sets to be concatenated together

        auto mergeStack = [](const vector<set<string>>& stack) -> set<string> {
            set<string> res = {""};
            for (const auto& s : stack) {
                set<string> nextRes;
                for (const auto& a : res) {
                    for (const auto& b : s) {
                        nextRes.insert(a + b);
                    }
                }
                res = move(nextRes);
            }
            return res;
        };

        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == ',') {
                // Perform concatenation for the current chunk and union it
                set<string> merged = mergeStack(concatStack);
                unionSet.insert(merged.begin(), merged.end());
                concatStack.clear();
                i++;
            } else if (expr[i] == '{') {
                i++; // Skip '{'
                concatStack.push_back(parse(expr, i));
                i++; // Skip '}'
            } else { // Lowercase letter
                string s = "";
                while (i < expr.length() && isalpha(expr[i])) {
                    s += expr[i];
                    i++;
                }
                concatStack.push_back({s});
            }
        }

        // Process remaining concatenated terms
        set<string> merged = mergeStack(concatStack);
        unionSet.insert(merged.begin(), merged.end());

        return unionSet;
    }
};