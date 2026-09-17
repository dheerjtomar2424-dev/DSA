class Solution {
    vector<int> nums;
    vector<char> ops;
    vector<int> memo[25][25];

    vector<int> solve(int i, int j) {
        if (!memo[i][j].empty()) return memo[i][j];

        if (i == j) {
            return memo[i][j] = {nums[i]};
        }

        vector<int> res;
        for (int k = i; k < j; ++k) {
            vector<int> left = solve(i, k);
            vector<int> right = solve(k + 1, j);
            char op = ops[k];

            for (int l : left) {
                for (int r : right) {
                    if (op == '+') res.push_back(l + r);
                    else if (op == '-') res.push_back(l - r);
                    else if (op == '*') res.push_back(l * r);
                }
            }
        }
        return memo[i][j] = res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        int val = 0;

        for (int i = 0; i < n; ++i) {
            if (isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
            } else {
                nums.push_back(val);
                val = 0;
                ops.push_back(expression[i]);
            }
        }
        nums.push_back(val);

        int m = nums.size();
        return solve(0, m - 1);
    }
};