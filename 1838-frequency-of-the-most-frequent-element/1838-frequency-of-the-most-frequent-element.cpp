class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, ans = 0;
        long long sum = 0;

        for(int right = 0; right < n; right++) {
            sum += nums[right]; 
            long long op = (long long)nums[right] * (right - left + 1) - sum;
            
            while(op > k) {
                sum -= nums[left]; 
                left++;
                op = (long long)nums[right] * (right - left + 1) - sum;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};