class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Pass 1: Find candidate majority elements
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Pass 2: Verify candidates appear more than ⌊n / 3⌋ times
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> result;
        int threshold = nums.size() / 3;
        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold) result.push_back(candidate2);

        return result;
    }
};