class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> minSuffix(n + 1, INT_MAX);

        for(int i = n - 1; i >= 0; --i) {
            minSuffix[i] = min(nums[i], minSuffix[i + 1]);
        }

        vector<int> ans(n);
        int l = 0;

        while(l < n) {
            int r = l;
            int componentMax = nums[l];

            while(r + 1 < n && componentMax > minSuffix[r + 1]) {
                ++r;
                componentMax = max(componentMax, nums[r]);
            }

            for(int i = l; i <= r; ++i) {
                ans[i] = componentMax;
            }

            l = r + 1;
        }

        return ans;
    }
};