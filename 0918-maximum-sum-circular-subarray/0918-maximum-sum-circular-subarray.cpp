class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxx = nums[0], minn = nums[0];
        int currMaxSum = nums[0], currMinSum = nums[0];
        int total = nums[0];
        
        for(int i = 1; i < n; i++) {
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxx = max(maxx, currMaxSum);   
            currMinSum = min(currMinSum + nums[i], nums[i]);
            minn = min(minn, currMinSum);
            total += nums[i];
        }
        
        int circularSum = total - minn;
        
        if(circularSum == 0) {
            return maxx;
        }
        
        return max(maxx, circularSum);
    }
};