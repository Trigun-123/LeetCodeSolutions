class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n);
        
        stack<int> st;
       
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            result[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return result;
    }

    vector<int> findPSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> result(n);

        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            result[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return result;
    }
    
public:
    int sumSubarrayMins(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        
        int n = arr.size();
        int mod = 1e9 + 7; 

        int sum = 0;
        for(int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
         
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};