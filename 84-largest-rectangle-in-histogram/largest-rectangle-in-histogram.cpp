class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxi = 0;

        for(int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : heights[i];

            while(!st.empty() && heights[st.top()] > curr) {
                int height = heights[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                int width = nse - pse - 1;
                int area = height * width;

                maxi = max(maxi, area);
            }

            st.push(i);
        }

        return maxi;
    }
};