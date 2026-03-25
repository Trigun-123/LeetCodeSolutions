class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        
        for(auto it : grid) {
            for(auto x : it) {
                total += x;
            }
        }        
        
        if(total % 2) {
            return false;
        }    
        
        long long tar = total / 2, sum = 0;
        
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                sum += grid[i][j];
            }    
            if(sum == tar) {
                return true;
            }    
        }
        
        sum = 0;
        
        for(int j = 0; j < n - 1; j++) {
            for(int i = 0; i < m; i++) {
                sum += grid[i][j];
            }    
            if(sum == tar) {
                return true;
            }    
        }
        
        return false;
    }
};