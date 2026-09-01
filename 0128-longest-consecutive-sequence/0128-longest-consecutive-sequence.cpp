class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for (int num : st) {

            // Start only from the beginning of a sequence
            if (!st.count(num - 1)) {

                int current = num;
                int length = 1;

                while (st.count(current + 1)) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};