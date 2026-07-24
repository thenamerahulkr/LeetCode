class Solution {
private:
    vector<int> getPSE(const vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> getNSE(const vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> PSE = getPSE(heights);
        vector<int> NSE = getNSE(heights);
        int maxArea = INT_MIN;
        for(int i = 0; i < n; i++){     
            int breadth = (NSE[i] - PSE[i] - 1);
            int height = heights[i];
            int area = breadth * height;
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};