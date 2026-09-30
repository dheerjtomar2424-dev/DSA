class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.size());
        int depth = 0;
        
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                depth++;
                ans[i] = depth % 2; // Assign based on current depth parity
            } else {
                ans[i] = depth % 2; // Match the corresponding opening bracket's group
                depth--;
            }
        }
        
        return ans;
    }
};