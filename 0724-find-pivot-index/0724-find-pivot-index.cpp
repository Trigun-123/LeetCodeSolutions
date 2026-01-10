class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftTotal = 0;

        for(int i = 0; i < n; i++) {
            int rightTotal = totalSum - leftTotal - nums[i];
            if(rightTotal == leftTotal) {
                return i;
            }
            leftTotal += nums[i];
        }      

        return -1;
    }
};