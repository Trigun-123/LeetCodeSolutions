class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        
        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        
        int result = INT_MAX;
        
        for(auto it : mpp) {
            vector<int>& v = it.second;
            int m = v.size(); 

            for(int j = 0; j + 2 < m; j++) {
                int value = 2 * (v[j + 2] - v[j]);
                result = min(result, value);
            }
        }
        
        return (result == INT_MAX) ? -1 : result;
    }
};