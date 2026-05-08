class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;

        while(n != 0) {
            int temp = n % 2;

            if(temp) {
                result++;
            }
            n /= 2;
        }

        return result;
    }
};