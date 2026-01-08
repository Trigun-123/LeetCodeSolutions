class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> v = score;
        sort(v.rbegin(), v.rend());
        unordered_map<int, string> mpp;

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                mpp[v[i]] = "Gold Medal";
            }    
            else if(i == 1) {
                mpp[v[i]] = "Silver Medal";
            }    
            else if(i == 2) {
                mpp[v[i]] = "Bronze Medal";
            }    
            else {
                mpp[v[i]] = to_string(i + 1);
            }    
        }

        vector<string> result;

        for(int i = 0; i < n; i++) {
            result.push_back(mpp[score[i]]);
        }

        return result;
    }
};