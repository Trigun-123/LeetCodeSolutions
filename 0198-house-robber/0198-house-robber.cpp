class Solution {
private:
    int rec(int i, vector<int> &nums, int n, vector<int> &dp) {
        if(i >= n)
            return 0;

        if(dp[i] != -1)
            return dp[i];
        
        int notTaken = rec(i+1, nums, n, dp);
        int taken = nums[i] + rec(i+2, nums, n, dp);

        return dp[i] = max(notTaken, taken);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rec(0, nums, n, dp);
    }
};