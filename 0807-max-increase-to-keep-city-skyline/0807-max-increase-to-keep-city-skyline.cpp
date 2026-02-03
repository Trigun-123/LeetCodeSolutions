class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(); 
        vector<int>row(n, INT_MIN);
        vector<int>column(n, INT_MIN);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                column[j] = max(column[j], grid[i][j]);
            }
        }
 
        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                result += min(row[i], column[j]) - grid[i][j];
            }
        }

        return result;
    }
};