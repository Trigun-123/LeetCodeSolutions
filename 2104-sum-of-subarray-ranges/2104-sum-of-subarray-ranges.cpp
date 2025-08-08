class Solution {
private:
    vector<int> findNSE(vector<int> &nums) {
        int n = ums.size();
        vector<int> result(n);

        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            result[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return result;
    }

    vector<int> findNGE(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n);

        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            result[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return result;
    }

    vector<int> findPSEE(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n);

        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            result[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return result;
    }

    vector<int> findPGEE(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n);

        stack<int> st;

        for(int i = 0; i < n ; i++) {
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            result[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return result;
    }

    long long sumSubarrayMins(vector<int> &nums) {
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);

        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            long long freq = left*right*1LL;
            long long val = freq*nums[i]*1LL;

            sum += val;
        }
        return sum;
    } 

    long long sumSubarrayMaxs(vector<int> &nums) {
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        int n = nums.size();
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            long long freq = left*right*1LL;
            long long val = freq*nums[i]*1LL;

            sum += val;
        }
        return sum;
    }    
public:
    long long subArrayRanges(vector<int> &nums) {
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};
