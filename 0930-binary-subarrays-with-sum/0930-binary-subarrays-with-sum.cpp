class Solution {
private:
    int countSubArrays(vector<int>& nums, int goal) {
        if(goal < 0)
            return 0;
        int n = nums.size();
        int l = 0, r = 0, sum = 0, count = 0;

        while(r < n) {
            sum += nums[r]; 
            while(sum > goal) {
                sum -= nums[l];  
                l++;            
            }
            count += (r - l + 1);
            r++; 
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubArrays(nums, goal) - countSubArrays(nums, goal - 1);
    }    
};