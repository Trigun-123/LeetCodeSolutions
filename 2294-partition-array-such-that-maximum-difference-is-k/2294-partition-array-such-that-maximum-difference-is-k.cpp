class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mine = nums[0], result = 1;

        for(int i = 1; i < n; i++) {
            if(num - minValue > k) {
                result++;
                minValue = nums[i];
            }
        }

        return result;
    }
};