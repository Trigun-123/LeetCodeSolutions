class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m  = grid[0].size();
        vector<int> temp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        sort(temp.begin(), temp.end());
        int first = temp[0], median = temp[temp.size()/2];
        int result = 0;

        for(int i = 0; i < temp.size(); i++) {
            int it = temp[i] - first;

            if(it % x != 0) {
                return -1;
            }

            first = temp[i];
            result += (abs(median-temp[i])/x);
        }

        return result;
    }
};