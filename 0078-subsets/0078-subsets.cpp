class Solution {
public:	
    vector<vector<int> > subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> result;

        for(int num = 0; num <= subsets-1; num++) {
            vector<int> subset;

            for(int i = 0; i < n; i++) {
                if(num & (1 << i))
                    subset.push_back(nums[i]);
            }
            result.push_back(subset);
        }
        return result;
    }
};