class Solution {
private:
    bool solve(long long T, int h, vector<int>& w) {
        long long total = 0;

        for(auto it : w) {
            long  value = (2 * T) / it;
            long long x = (long long)((sqrt(1 + 4.0 * value) - 1) / 2);
            total += x;

            if(total >= h) {
                return true;
            }    
        }

        return false;
    }

public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes){
        long long left = 0, right = 1e18, result = right;

        while(left <= right) {
            long long mid = (left + right) / 2;

            if(solve(mid, mountainHeight, workerTimes)) {
                result = mid;
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }

        return result;
    }
};