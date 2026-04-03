class Solution {
private:
    int solve2(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        int totalSum = 0;

        for(int i = 0 ; i < n; i++) {
            int x = 1;
            for(int j = m-1; j >= 0; j--) {
                if(grid[i][j] == 1) {
                    totalSum += x;
                }    
                x *= 2; 
            }
        }

        return totalSum;
    }

    void solve1(vector<vector<int>>& grid, int m) {
        int n = grid.size();

        for(int i = 0; i < n; i++) {
            grid[i][m] ^= 1;
        }
    }

public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j < m; j++) {
                    grid[i][j] ^= 1;
                }    
            }
        }

        for(int i = 0; i < m; i++) {
            int count0 = 0, count1 = 0;
            for(int j = 0; j < n; j++) {
                if(grid[j][i] == 0) {
                    count0 += 1;
                }    
                else {
                    count1 += 1; 
                }    
            }
            if(count0 > count1) {
                solve1(grid, i);
            }    
        }

        return solve2(grid);
    }
};