class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> result(k, 0);
        unordered_map<int, set<int>> mpp;

        for(auto it : logs) {
            mpp[it[0]].insert(it[1]);
        }

        for(auto it : mpp) {
            int activeMinutes = it.second.size();
            result[activeMinutes - 1]++;
        }

        return result;
    }
};