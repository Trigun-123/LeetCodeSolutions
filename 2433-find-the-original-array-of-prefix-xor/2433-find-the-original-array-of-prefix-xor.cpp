class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> result;
        result.push_back(pref[0]);

        for(int i = 1; i < n; i++) {
            int it = pref[i] ^ pref[i-1];
            result.push_back(it);
        }

        return result;
    }
};