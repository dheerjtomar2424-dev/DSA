#pragma GCC optimize("O3")

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Step 1: XOR all elements to get xorSum = A ^ B
        long long xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        // Step 2: Get the rightmost set bit (lowest set bit)
        // Using long long prevents signed integer overflow when xorSum is INT_MIN
        long long diffBit = xorSum & (-xorSum);

        // Step 3: Divide numbers into two groups and XOR within each group
        int a = 0, b = 0;
        for (int num : nums) {
            if (num & diffBit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};