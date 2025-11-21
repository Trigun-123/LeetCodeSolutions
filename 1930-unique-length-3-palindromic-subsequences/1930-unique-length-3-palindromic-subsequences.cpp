class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;

        for(int i = 0; i < 26; i++) {
            char forward = 'a' + i;
            int start = -1;
            int end = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] == forward) {
                    if(start == -1) 
                        start = i;
                    end = i;
                }
            }

            if(start == -1 || start == end) 
                continue;

            set<char> distinct;

            for(int i = start + 1; i < end; i++)
                distinct.insert(s[i]);

            result += distinct.size();
        }

        return result;
    }
};