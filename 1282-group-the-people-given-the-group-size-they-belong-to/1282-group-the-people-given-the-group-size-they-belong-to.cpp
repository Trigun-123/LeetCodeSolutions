class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> result;
        unordered_map<int, vector<int>> mpp;
        
        for(int i = 0; i < n; i++) {
            int sizes = groupSizes[i];
            mpp[sizes].push_back(i); 
            if(mpp[sizes].size() == sizes) { 
                result.push_back(mpp[sizes]);
                mpp[sizes] = {}; 
            }
        }
        
        return result;
    }
};