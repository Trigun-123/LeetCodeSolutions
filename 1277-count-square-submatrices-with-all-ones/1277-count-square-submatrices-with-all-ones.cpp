class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dpTable(r, vector<int>(c, 0));
        int result = 0;
        
        for(int i = 0; i < r; i++) {
            dpTable[i][0] = matrix[i][0];
            result += dpTable[i][0];
        }
        
        for(int j = 1; j < c; j++) {
            dpTable[0][j] = matrix[0][j];
            result += dpTable[0][j];
        }
        
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(matrix[i][j] == 1) {
                    dpTable[i][j] = 1 + min({dpTable[i][j-1], dpTable[i-1][j], dpTable[i-1][j-1]});
                }
                result += dpTable[i][j];
            }
        }
        
        return result;
    }
};