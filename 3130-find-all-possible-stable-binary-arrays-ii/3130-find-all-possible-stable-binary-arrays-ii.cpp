class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<long long>> dpZero(zero + 1, vector<long long>(one + 1, 0));
        vector<vector<long long>> dpOne(zero + 1, vector<long long>(one + 1, 0));

        for(int i = 1; i <= min(zero, limit); i++) {
            dpZero[i][0] = 1;
        }
        for(int j = 1; j <= min(one, limit); j++) {
            dpOne[0][j] = 1;
        }

        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }    
                if(i > 0 && j > 0) {
                    dpZero[i][j] = (dpZero[i - 1][j] + dpOne[i - 1][j]) % mod;
                    if(i - limit - 1 >= 0) {
                        dpZero[i][j] = (dpZero[i][j] - dpOne[i - limit - 1][j] + mod) % mod;
                    }
                    dpOne[i][j] = (dpOne[i][j - 1] + dpZero[i][j - 1]) % mod;
                    if(j - limit - 1 >= 0) {
                        dpOne[i][j] = (dpOne[i][j] - dpZero[i][j - limit - 1] + mod) % mod;
                    }
                }
            }
        }            
         
        return (dpZero[zero][one] + dpOne[zero][one]) % mod;
    }
};