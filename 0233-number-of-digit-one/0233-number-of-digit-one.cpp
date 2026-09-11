class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;
        
        for (long long m = 1; m <= n; m *= 10) {
            long long prefix = n / (m * 10);
            long long cur = (n / m) % 10;
            long long suffix = n % m;
            
            count += prefix * m;
            
            if (cur == 1) {
                count += suffix + 1;
            } else if (cur > 1) {
                count += m;
            }
        }
        
        return count;
    }
};