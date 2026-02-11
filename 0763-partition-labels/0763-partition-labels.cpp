class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[s[i]] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        for(int i = 0; i < n; i++) {
            end = max(end, mpp[s[i]]);
            if(i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};