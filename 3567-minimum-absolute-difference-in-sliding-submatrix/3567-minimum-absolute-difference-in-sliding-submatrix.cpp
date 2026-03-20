class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1, 0));

        for(int i = 0; i <= m - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                vector<int> temp;
                for(int l = i; l < i + k; l++) {
                    for(int y = j; y < j + k; y++) {
                        temp.push_back(grid[l][y]);
                    }
                }

                if(k == 1) {
                    result[i][j] = 0;
                    continue;
                }

                sort(temp.begin(), temp.end());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());
                int size = temp.size();
                if(size <= 1) {
                    result[i][j] = 0;
                    continue;
                }

                int minn = INT_MAX;
                for(int p = 1; p < size; p++) {
                    minn = min(minn, abs(temp[p] - temp[p - 1]));
                }
                result[i][j] = minn;
            }
        }

        return result;
    }
};