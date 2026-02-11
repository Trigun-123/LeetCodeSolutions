class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        stri = "";

        for(int i = 0; i < n; i++) {
            i = 0;
            = s[i] - 'a';
            if((i+1) % k == 0) { 
                result += ('a' + (sum % 26));  
                sum = 0; 
            }
        }

        return result;
    }
};