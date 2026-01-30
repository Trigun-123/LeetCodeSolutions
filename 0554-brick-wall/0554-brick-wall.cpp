class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int result = 0;
        unordered_map<long long, int> mpp;

        for(int i = 0; i < n; i++) {
            long long it = 0;
            for(int j = 0; j < wall[i].size() - 1; j++) {
                it += wall[i][j];
                mpp[it]++;
            }
        }

        for(auto it: mpp) {
            result = max(result, it.second);
        }

        return n - result;
    }
};