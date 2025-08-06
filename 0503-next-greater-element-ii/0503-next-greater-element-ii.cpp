class Solution {
public:
    vector<int> nextGreaterElements(vector<int> arr) {
        int  = arr.size(); 
        vector<int> ans(n);
        
        stack<int> st;
        for(int i = 2*n-1; i >= 0; i--) {
            int index = i % n;
            while(st.empty() == false && st.top() <= arr[index])
                st.pop();
            if(i < n) {
                if(st.empty()) 
                    ans[i] = -1;
                else 
                    ans[i] = st.top();
            }
            st.push(arr[index]);
        }
        return ans;
    }
};