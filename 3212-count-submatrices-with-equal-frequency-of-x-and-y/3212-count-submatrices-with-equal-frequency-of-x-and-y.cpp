class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> difference(m, 0), hasX(m, 0);   
        int result = 0;

        for(int i = 0; i < n; i++) {
            int rowDifference = 0, rowHasX = 0;   

            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'X') {
                    rowDifference++;
                    rowHasX = 1;
                } 
                else if(grid[i][j] == 'Y') {
                    rowDifference--;
                }

                difference[j] += rowDifference;
                hasX[j] |= rowHasX;

                if(hasX[j] && difference[j] == 0) {
                    result++;
                }
            }
        }

        return result;
    }
};