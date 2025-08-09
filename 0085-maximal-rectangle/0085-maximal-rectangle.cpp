class Solution{
private:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(); 
        stack<int> st;
        int maxArea = 0, nse, pse;
        
        for(int i = 0; i < n; i++) {
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

public:
    int maximalRectangle(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> prexSum(n, vector<int>(m));

        for(int j = 0; j < m; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += matrix[i][j];

                if(matrix[i][j] == 0) {
                    prefixSum[i][j] = 0;
                    sum = 0;
                }
                prefixSum[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int area = largestRectangleArea(prefixSum[i]);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};