class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }

        unordered_set<int> occurrence;

        for(auto it : mpp) {
            if(occurrence.find(it.second) != occurrence.end()) {
                return false;
            }
            occurrence.insert(it.second);
        }

        return true;
    }
};