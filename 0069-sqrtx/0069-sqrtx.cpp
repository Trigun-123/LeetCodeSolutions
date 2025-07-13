class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;

        int low = 0, high = x, ans = 0;

        while(low <= high) {
            int mid = (low + high) / 2;
            int midSquare = mid * mid;

            if(midSquare > x)
                high = mid - 1;
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};