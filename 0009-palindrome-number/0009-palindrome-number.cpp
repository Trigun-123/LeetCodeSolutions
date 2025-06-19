class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = x;
        long reversedNumber = 0;

        while(temp != 0) {
            int lastDigit = temp % 10;
            reversedNumber = reversedNumber * 10 + lastDigit;
            temp /= 10; 
        }
        return reversedNumber == x;
    }
};