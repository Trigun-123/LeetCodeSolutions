class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int zerocount = 0;

        for(auto it : s) {
            if(it == '0') {
                zerocount++;
            }
        }        

        if(zerocount == 0) {
            return 0 ;
        }    
        if(k == n) {
            return (zerocount == n) ? 1 : -1 ;
        }    

        int result = INT_MAX;
        
        if(zerocount % 2 == 0) {
            int temp = max((zerocount + k - 1) / k , (zerocount + n - k - 1) / (n-k));
            result = (temp % 2 == 0) ? temp : temp + 1 ; 
        }       
        if(zerocount % 2 == k % 2) {
            int temp = max((zerocount + k - 1) / k , (n - zerocount + n - k - 1) / (n-k));
            result = min(result, ((temp % 2 == 1) ? temp : temp + 1)); 
        }

        return (result == INT_MAX)? -1 : result;
    }
};