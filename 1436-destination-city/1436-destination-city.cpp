class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sourceCities;

        for(auto it : paths) {
            sourceCities.insert(it[0]);
        }

        for(auto it : paths) {
            if(sourceCities.find(it[1]) == sourceCities.end()) {
                return it[1];
            }
        }

        return "";
    }
};