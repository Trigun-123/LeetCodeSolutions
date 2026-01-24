class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0, left = 0;
        int result = INT_MAX;

        for(int i = 0 ; i < n; i++){
            sum += nums[i];
        
            while(sum >= target) {
                result = min(result, i - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        if(result == INT_MAX) {
            return 0;
        }   

        return result;
    }
};