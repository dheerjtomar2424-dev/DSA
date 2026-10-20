#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    long long sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());

        long long total_sum = 0;

        // Pre-map values or use fast checks
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool possible = true;
            for (int i = 0; i < n; i += k) {
                // Quick check: if the block is already identical
                bool identical = true;
                for (int m = 0; m < k; ++m) {
                    if (nums[i + m] != sorted_nums[i + m]) {
                        identical = false;
                        break;
                    }
                }
                if (identical) continue;

                // For general blocks, check if sorted_nums[i ... i+k-1] 
                // is a cyclic rotation of nums[i ... i+k-1].
                // We can do this efficiently by checking if the sorted subarray 
                // appears in nums[i...i+k-1] + nums[i...i+k-1].
                // To avoid string allocation overhead, we can use a optimized two-pointer / KMP or frequency + match check.
                
                int target_val = sorted_nums[i];
                bool matched = false;
                
                for (int offset = 0; offset < k; ++offset) {
                    if (nums[i + offset] == target_val) {
                        bool ok = true;
                        for (int m = 0; m < k; ++m) {
                            if (nums[i + (offset + m) % k] != sorted_nums[i + m]) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            matched = true;
                            break;
                        }
                        // Skip duplicate values to ensure 0ms performance on identical elements
                        while (offset + 1 < k && nums[i + offset + 1] == nums[i + offset]) {
                            offset++;
                        }
                    }
                }

                if (!matched) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                total_sum += k;
            }
        }

        return total_sum;
    }
};