class Solution {
private:
    vector<int> computeLPS(string s) {
        int n = s.size(); 
        vector<int> LPS(n, 0);
        int i = 1, j = 0;
        
        while(i < n) {
            if(s[i] == s[j]) {
                LPS[i] = j + 1;
                i++; j++;
            } else {
                if(j != 0) {
                    j = LPS[j - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS;
    }
    
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;

        string combined = needle + '$' + haystack;
        vector<int> LPS = computeLPS(combined);
        int m = needle.size();

        for(int i = m + 1; i < combined.size(); i++) {
            if(LPS[i] == m)
                return i - 2 * m;
        }
        return -1;
    }
};
