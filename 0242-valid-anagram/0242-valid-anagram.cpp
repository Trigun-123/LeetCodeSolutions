class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
            
        int n = s.length();
        int freqS[26] = {0};
        int freqT[26] = {0};

        for(int i = 0; i <= n-1; i++) {
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }

        for(int i = 0; i <= 25; i++) {
            if(freqS[i] != freqT[i])
                return false;
        }
        return true;
    }
};