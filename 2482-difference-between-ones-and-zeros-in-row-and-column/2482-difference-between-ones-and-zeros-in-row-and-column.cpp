class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowOnes(n, 0);
        vector<int> colOnes(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rowOnes[i] += grid[i][j];
                colOnes[j] += grid[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = 2 * (rowOnes[i] + colOnes[j]) - n - m;
            }
        }

        return grid;
    }
};
