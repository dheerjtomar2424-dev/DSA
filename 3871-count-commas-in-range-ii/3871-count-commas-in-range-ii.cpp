class Solution {
public:
    long long countCommas(long long n) {
        long long totalCommas = 0;
        long long threshold = 1000; // 10^3

        while (n >= threshold) {
            totalCommas += (n - threshold + 1);
            // Prevent 64-bit integer overflow when threshold exceeds 10^15
            if (threshold > n / 1000) {
                break;
            }
            threshold *= 1000;
        }

        return totalCommas;
    }
};