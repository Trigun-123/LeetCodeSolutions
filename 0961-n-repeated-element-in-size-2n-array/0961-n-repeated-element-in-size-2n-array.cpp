class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;

        for(auto it : nums) {
            if(st.count(it)) {
                return it;
            }
            st.insert(it);
        }

        return -1;
    }
};