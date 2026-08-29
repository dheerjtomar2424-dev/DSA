class Solution {
public:
    vector<int> grayCode(int n) {

        int size = 1 << n;
        vector<int> ans;
        ans.reserve(size);

        for (int i = 0; i < size; i++) {
            ans.push_back(i ^ (i >> 1));
        }

        return ans;
    }
};