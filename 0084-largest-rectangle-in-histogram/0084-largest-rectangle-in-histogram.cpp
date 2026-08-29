class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        vector<int> st;
        st.reserve(n + 1);

        int ans = 0;

        for (int i = 0; i <= n; i++) {

            int h = (i == n ? 0 : heights[i]);

            while (!st.empty() && heights[st.back()] > h) {

                int height = heights[st.back()];
                st.pop_back();

                int left = st.empty() ? -1 : st.back();

                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push_back(i);
        }

        return ans;
    }
};
