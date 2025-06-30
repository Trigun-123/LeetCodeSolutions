class Solution {
private:
    bool possible(vector<int> &nums, int day, int m, int k) {
        int n = nums.size(); 
        int cnt = 0; 
        int noOfB = 0; 

        for(int i = 0; i < n; i++) {
            if(nums[i] <= day)
                cnt++; 
            else {
                noOfB += (cnt / k);
                cnt = 0; 
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m; 
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = (long long)m * k;
        if(val > n)
            return -1; 
        int mini = INT_MAX, maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]); 
            maxi = max(maxi, bloomDay[i]); 
        }

        int left = mini, right = maxi, ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2; 
            if(possible(bloomDay, mid, m, k)) {
                ans = mid; 
                right = mid - 1; 
            }
            else
                left = mid + 1; 
        }
        return ans;  
    }
};