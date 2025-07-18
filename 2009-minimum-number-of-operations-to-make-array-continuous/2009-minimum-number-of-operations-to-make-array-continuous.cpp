class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() - 1;
        int maxi = 0;
        int count = 0;  
        int left = 0;  
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n+1; i++) {
            if(i+1 < n+1 && nums[i] == nums[i+1])
                continue;
            nums[left++] = nums[i];
        }

        for(int i = 0, j = 0; i < left; i++) {
            while(j < left && (nums[j] - nums[i]) <= n) {
                count++;
                j++;
            }
            maxi = max(maxi, count);
            count--;
        }
        return n+1 - maxi;
    }
};