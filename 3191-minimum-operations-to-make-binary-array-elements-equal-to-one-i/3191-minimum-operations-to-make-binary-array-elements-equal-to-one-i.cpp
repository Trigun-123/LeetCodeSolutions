class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(in 0; i < n - 2; i++) {
            if(nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }
        
        if(nums[n - 2] == 1 ms[n - 1] == 1) {
            return count;
        }
        else {
            return -1;
        }
    }
};