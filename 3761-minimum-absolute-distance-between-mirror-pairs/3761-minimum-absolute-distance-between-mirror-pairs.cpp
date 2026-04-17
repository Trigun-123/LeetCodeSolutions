class Solution {
private:
    int solve(int it) {
        int ans = 0;

        while(it != 0) {
            ans = ans*10 + it%10;
            it /= 10;
        }

        return ans;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int result = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(mpp.count(nums[i])) {
                result = min(result, i - mpp[nums[i]]);
            }
            int reverse = solve(nums[i]);
            mpp[reverse] = i;
        }

        if(result == INT_MAX) {
            return -1;
        }
        else {
            return result;
        } 
    }
};