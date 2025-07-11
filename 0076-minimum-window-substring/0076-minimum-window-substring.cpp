class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minLen = INT_MAX;
        int sIndex = -1;
        int hash[256] = {0};

        for(char it : t)
            hash[it]++;
            
        int count = 0, l = 0, r = 0;
    
        while(r < n) {
            if (hash[s[r]] > 0)
                count++;
            hash[s[r]]--;
            while (count == m) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0)
                    count--;
                l++;
            }
            r++;
        }
        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};
