class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int MOD = 12345;
        vector<int> array;

        for(auto it : grid) {
            for(auto x : it) {
                array.push_back(x % MOD);
            }
        }        

        int size = array.size();
        vector<int> prefix(size, 1), suffix(size, 1);

        for(int i = 1; i < size; i++) {
            prefix[i] = (1LL * prefix[i - 1] * array[i - 1]) % MOD;
        }

        for(int i = size - 2; i >= 0; i--) {
            suffix[i] = (1LL * suffix[i + 1] * array[i + 1]) % MOD;
        }

        vector<vector<int>> result(n, vector<int>(m));
        int index = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = (1LL * prefix[index] * suffix[index]) % MOD;
                index++;
            }
        }

        return result;
    }
};