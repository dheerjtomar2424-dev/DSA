class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Store {number, frequency}
        vector<pair<int, int>> arr;

        for (auto x : mp) {
            arr.push_back({x.first, x.second});
        }

        // Sort by frequency
        sort(arr.begin(), arr.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second > b.second;
             });

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};