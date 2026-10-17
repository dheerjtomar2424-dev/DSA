class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store pairs of {number, original_index}
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        // Sort using custom comparator: primary by digit sum, secondary by value
        auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        };
        
        sort(arr.begin(), arr.end(), comp);
        
        // Find the minimum number of swaps using cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            // If already visited or already in the correct position
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            // Traverse the cycle
            int cycleSize = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = arr[curr].second;
                cycleSize++;
            }
            
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }
        
        return swaps;
    }
};