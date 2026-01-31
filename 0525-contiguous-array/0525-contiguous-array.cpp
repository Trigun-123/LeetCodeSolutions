class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int currSum = 0, result = 0;
 
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                currSum++;
            }
            else {
                currSum--;
            }
            if(mpp.find(currSum) != mpp.end()) {
                result = max(result, i - mpp[currSum]);
            }
            else {
                mpp[currSum] = i;
            }
        }

        return result;
    }
};