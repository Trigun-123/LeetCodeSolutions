class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int productOfThreeNumbers = 1;

        for(int i = 0; i < n; i++) {
            productOfThreeNumbers *= nums[i];
        }

        return productOfThreeNumbers;
    }
};