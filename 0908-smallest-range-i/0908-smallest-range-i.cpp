class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minn = INT_MAX, maxx = INT_MIN;
        
        for(auto it : nums) {
            minn = min(minn, it);
            maxx = max(maxx, it);
        }
        
        int range = maxx - minn - 2 * k;

        return max(0, range);
    }
};