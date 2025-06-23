class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n-2; i++) {
            int minimum = i;
            for(int j = i; j <= n-1; j++) {
                if(nums[j] < nums[minimum])
                    minimum = j;
            }
            swap(nums[minimum], nums[i]); 
        }
    }
};