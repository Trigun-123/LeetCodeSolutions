class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int MODULO = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            int start = queries[i][0], end = queries[i][1];
            int step = queries[i][2], factor = queries[i][3];

            for(int j = start; j <= end; j += step) {
                nums[j] = (1LL * nums[j] * factor) % MODULO;
            }
        }

        int result = 0;

        for(auto it : nums) {
            result ^= it;
        }

        return result;
    }
};