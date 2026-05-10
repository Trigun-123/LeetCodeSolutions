class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dpp(n, -1);
        dpp[0] = 0;

        for(int i = 0; i < n; i++) {
            if(dpp[i] == -1) {
                continue;
            }    

            for(int j = i + 1; j < n; j++) {
                long long difference = 1LL * nums[j] - nums[i];

                if(-target <= difference && difference <= target) {
                    dpp[j] = max(dpp[j], dpp[i] + 1);
                }
            }
        }

        return dpp[n - 1];
    }
};