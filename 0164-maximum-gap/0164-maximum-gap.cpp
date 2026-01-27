class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int diff = 0, maxDiff = 0;

        for(int i = 1; i < n; i++) {
            diff = nums[i] - nums[i-1];
            maxDiff = max(diff, maxDiff);
        }

        return maxDiff;
    }
};