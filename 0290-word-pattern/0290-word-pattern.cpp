class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size(), m = s.size();
        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;

        int i = 0, j = 0;

        while(i < n) {
            if(j >= m) {
                return false;
            }    

            int start = j;
            while(j <  m&& s[j] != ' ') {
                j++;
            }    

            string word = s.substr(start, j - start);
            if(mpp1.count(pattern[i]) && mpp1[pattern[i]] != word) {
                return false;
            }    
            if(mpp2.count(word) && mpp2[word] != pattern[i]) {
                return false;
            }    

            mpp1[pattern[i]] = word;
            mpp2[word] = pattern[i];
            j++;
            i++;
        }

        return j >= m;
    }
};