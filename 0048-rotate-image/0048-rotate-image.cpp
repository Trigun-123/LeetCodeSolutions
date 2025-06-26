class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for(int i = 0; i <= n-2; i++) {
            for(int j = i+1; j <= n-1; j++)
                swap(matrix[i][j], matrix[j][i]);
        }

        // Reverse each row of the matrix
        for(int i = 0; i <= n-1; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};