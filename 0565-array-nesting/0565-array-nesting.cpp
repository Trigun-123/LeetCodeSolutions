class Solution {
private:
    int n;
    vector<int> dp;

    int dfs(int i, vector<int>& nums){
        if(i >= n) {
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        dp[i]=0;

        return dp[i] = 1 + dfs(nums[i], nums);
    }

public:
    int arrayNesting(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1);

        for(int i = 0; i < n; i++) {
            if(dp[i] == -1) {
                dp[i] = dfs(i, nums);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};