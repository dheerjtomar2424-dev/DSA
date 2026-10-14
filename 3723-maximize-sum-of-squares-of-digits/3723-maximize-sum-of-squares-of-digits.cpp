class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if ((long long)num * 9 < sum) {
            return "";
        }
        
        string ans = "";
        ans.reserve(num);
        
        for (int i = 0; i < num; ++i) {
            int rem_slots = num - 1 - i;
            int min_d = max(0, sum - rem_slots * 9);
            int max_d = min(9, sum);
            int d = max_d;
            ans += (char)('0' + d);
            sum -= d;
        }
        
        return (sum == 0) ? ans : "";
    }
};