class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int result = 0, previous = 0, current = 1;
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                current++;
            } 
            else {
                result += min(previous, current);
                previous = current;
                current = 1;
            }
        }

        return result + min(previous, current);
    }
};