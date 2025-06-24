class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxx = 0;
        int count = 0;

        for(int i = 0; i <= n-1; i++) {
            if(nums[i] == 1) {
                count++;
                maxx = max(maxx, count);
            }
            else  
                count = 0;
        }
        return maxx;
    }
};