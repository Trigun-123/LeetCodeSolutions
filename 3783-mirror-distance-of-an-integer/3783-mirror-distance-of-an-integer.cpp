class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        int reversedNumber = 0;

        while(temp != 0) {
            reversedNumber = reversedNumber*10 + temp%10;
            temp /= 10;
        }

        return abs(reversedNumber - n);
    }
};