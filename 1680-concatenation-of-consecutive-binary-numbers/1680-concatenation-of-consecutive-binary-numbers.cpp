class Solution {
public:
    int concatenatedBinary(int n) {
        long long mod = 1e9 + 7, result = 0;
        int bits = 0;

        for(int i = 1; i <= n; i++) {
            if((i & (i-1)) == 0) {
                bits++;
            }
            result = ((result << bits) | i) % mod;
        }
        
        return result;
    }
};