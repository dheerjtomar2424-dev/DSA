class Solution {
public:

    int largestRectangleArea(vector<int>& h) {

        vector<int> st;
        st.reserve(h.size());

        int ans = 0;

        for (int i = 0; i <= h.size(); i++) {

            int curr = (i == h.size()) ? 0 : h[i];

            while (!st.empty() && h[st.back()] > curr) {

                int height = h[st.back()];
                st.pop_back();

                int left = st.empty() ? -1 : st.back();

                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push_back(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int n = matrix[0].size();

        vector<int> height(n, 0);

        int ans = 0;

        for (auto& row : matrix) {

            for (int j = 0; j < n; j++) {

                if (row[j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};