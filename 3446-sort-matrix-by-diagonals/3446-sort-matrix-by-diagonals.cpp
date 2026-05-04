class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int row = 0; row < n; row++) {
            vector<int> temp;
            int i = row, j = 0;

            while(i < n && j < n) {
                temp.push_back(grid[i][j]);
                i++, j++;
            }

            sort(temp.rbegin(), temp.rend());

            i = row; j = 0;
            int k = 0;

            while(i < n && j < n) {
                grid[i++][j++] = temp[k++];
            }
        }

        for(int col = 1; col < n; col++) {
            vector<int> temp;
            int i = 0, j = col;

            while(i < n && j < n) {
                temp.push_back(grid[i][j]);
                i++, j++;
            }

            sort(temp.begin(), temp.end());

            i = 0; j = col;
            int k = 0;

            while(i < n && j < n) {
                grid[i++][j++] = temp[k++];
            }
        }

        return grid;
    }
};