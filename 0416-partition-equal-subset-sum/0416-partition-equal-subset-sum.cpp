class Solution {
private:
    bool rec(int i, int sum, int totalSum, vector<int> &nums, int n, vector<vector<int>> &dp) {
        // base case
        if(i == n)
            return sum == (totalSum / 2);
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        // recursive case
        bool notTake = rec(i+1, sum, totalSum, nums, n, dp);
        bool take = rec(i+1, sum+nums[i], totalSum, nums, n, dp);

        return dp[i][sum] = notTake || take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(auto &it : nums)
            totalSum += it;

        if(totalSum % 2 == 1)
            return false;

        vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
        
        return rec(0, 0, totalSum, nums, n, dp);
    }
};