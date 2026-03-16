class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            if(i > k) {
                st.erase(nums[i - k - 1]);
            }
            if(st.find(nums[i]) != st.end()) {
                return true;
            }
            st.insert(nums[i]);
        }

        return false;        
    }
};