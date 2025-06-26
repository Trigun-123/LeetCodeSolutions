class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int positiveIndex = 0, negativeIndex = 1;
        
        for(int i = 0; i <= n-1; i++) {
            if(nums[i] > 0) {
                result[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
            else {
                result[negativeIndex] = nums[i];
                negativeIndex += 2;
            }
        }
        return result;
    }
};