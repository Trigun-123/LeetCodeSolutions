class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        int low = 1;

        for(int i = 0; i < n; i++) {
            result[i] *= low;
            low *= nums[i];
        }

        int high = 1;

        for(int i = n - 1; i >= 0; i--) {
            result[i] *= high;
            high *= nums[i];
        }

        return result;        
    }
};