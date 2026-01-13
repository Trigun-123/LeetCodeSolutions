class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int first = 0, last = n - 1;

        if(nums[first] < nums[last]) {
            for(int i = 1; i < n; i++) {
                if(nums[i-1] > nums[i]) {
                    return false;
                }
            }        
        }
        else {
            for(int i = n - 2; i >= 0; i--) {
                if(nums[i] < nums[i+1])  {
                    return false;
                }
            }        
        }

        return true;    
    }
};