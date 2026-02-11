class Solution {
private:
    int func(vector<int>& nums, int n, int maxOR, int index, int currentOR) {
        if(index == n) {
            return currentOR == maxOR ? 1 : 0;
        }

        if(currentOR == maxOR) {
            return 1 << (n - index);
        }

        return func(nums, n, maxOR, index + 1, currentOR | nums[index]) +
               func(nums, n, maxOR, index + 1, currentOR);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for(auto it : nums) {
            maxOR |= it;
        }

        return func(nums, n, maxOR, 0, 0);
    }
};