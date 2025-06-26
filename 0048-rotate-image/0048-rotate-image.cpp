class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n, 0));

        for(int i = 0; i <= n-1; i++) {
            for(int j = 0; j <= n-1; j++)
                rotated[j][n-i-1] = matrix[i][j];
        }

        //copies rotated elements to matrix
        for(int i = 0; i < rotated.size(); i++) {
            for(int j = 0; j < rotated[0].size(); j++)
                matrix[i][j] = rotated[i][j];
        }
    }
};