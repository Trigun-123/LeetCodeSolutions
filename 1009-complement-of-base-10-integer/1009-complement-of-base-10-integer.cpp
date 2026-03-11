class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }    

        int bits = log2(n) + 1;
        int mask = (1 << bits) - 1;
        int result = n ^ mask;

        return result;
    }
};