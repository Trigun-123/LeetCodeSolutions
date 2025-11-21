class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n + 1, false);  

        for(int num : nums) {
            vis[num] = true;
        }

        vector<int> result;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};