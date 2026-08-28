class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;

        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        int fact = 1;

        for (int i = 1; i < n; i++)
            fact *= i;

        k--;

        string ans = "";

        for (int i = n; i > 0; i--) {

            int index = k / fact;

            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            if (i > 1) {
                k %= fact;
                fact /= (i - 1);
            }
        }

        return ans;
    }
};