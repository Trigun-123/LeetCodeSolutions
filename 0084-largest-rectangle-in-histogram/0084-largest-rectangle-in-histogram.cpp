class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(); 
        stack<int> st;
        int maxArea = 0, nse, pse;
        
        for(int i=0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int element = st.top(); 
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[element]*(nse-pse-1), maxArea);
            }
            st.push(i);
        }
    
        while(!st.empty()) {
            nse = n;
            int element = st.top(); 
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(heights[element]*(nse-pse-1), maxArea);
        }
        return maxArea;
    }
};