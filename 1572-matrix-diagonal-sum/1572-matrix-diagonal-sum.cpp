class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int i = 0, j = m - 1, count = 0;

        for(int k = 0; k < n; k++) {
            if(i == j) {
                count += mat[k][j];
            }    
            else {
                count += mat[k][i] + mat[k][j];
            }    
            i++;
            j--;
        }

        return count;
    }
};