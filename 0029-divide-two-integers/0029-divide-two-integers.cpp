class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1; 
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(divisor == 1)
            return dividend;

        bool sign = true;
        if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;
        
        long n = dividend, d = divisor;
        n = abs(n);
        d = abs(d);

        int answer = 0;

        while(n >= d) {
            int count = 0;
            while(n >= (d << (count+1)))
                count++;
            answer += (1 << count);
            n -= (d*(1 << count)); 
        }
        if(answer == (1 << 31) && sign == true) 
            return INT_MAX;
        if(answer == (1 << 31) && sign == false)
            return INT_MIN;
        return sign ? answer : (-answer);
    }
};