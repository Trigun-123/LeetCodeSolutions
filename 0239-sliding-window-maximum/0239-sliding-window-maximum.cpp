class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque <int> dq;

        for(int i = 0; i <= n-1; i++) {
          if(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();

          while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

          dq.push_back(i);

          if(i >= k-1)
            result.push_back(arr[dq.front()]); 
        }
        return result;
    }
};