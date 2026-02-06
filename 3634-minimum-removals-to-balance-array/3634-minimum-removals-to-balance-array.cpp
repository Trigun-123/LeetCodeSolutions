class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, maxLength = 0;
        
        for(int j = 0; j < n; j++) {
            while(nums[j] > nums[i] * k) {
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
        }
        
        return n - maxLength;
    }
};