class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        for(int i = 0; i <= n-1; i++) {
            if(nums[i] != 0)
                temp.push_back(nums[i]);
        }

        int nonZero = temp.size();

        for(int i = 0; i <= nonZero-1; i++)
            nums[i] = temp[i];

        for(int i = nonZero; i <= n-1; i++)
            nums[i] = 0;
    }
};