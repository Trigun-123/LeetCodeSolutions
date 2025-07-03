class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            unordered_map<char, int> mpp;
            for(int j = i; j < n; j++) {
                mpp[s[j]]++;

                int maxx = INT_MIN;
                int mini = INT_MAX;

                for (auto it : mpp) {
                    mini = min(mini, it.second);
                    maxx = max(maxx, it.second);
                }
                sum += (maxx - mini);
            }
        }
        return sum;
    }
};