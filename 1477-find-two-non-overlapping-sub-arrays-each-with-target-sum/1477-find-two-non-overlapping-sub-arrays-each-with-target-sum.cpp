class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a valid subarray ending at or before index i
        vector<int> min_len(n, 1e9);
        
        int left = 0;
        int current_sum = 0;
        int ans = 1e9;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];

            while (current_sum > target) {
                current_sum -= arr[left++];
            }

            if (current_sum == target) {
                int curr_len = right - left + 1;
                // If there exists a valid subarray strictly before `left`
                if (left > 0 && min_len[left - 1] != 1e9) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                // Update min_len for the current index
                min_len[right] = curr_len;
            }

            // Carry forward the minimum length seen so far
            if (right > 0) {
                min_len[right] = min(min_len[right], min_len[right - 1]);
            }
        }

        return ans >= 1e9 ? -1 : ans;
    }
};