class Solution {
private:
    vector<int> computeZarray(string s) {
        int n = s.size();
        vector<int> Z(n, 0);
        int left = 0, right = 0;

        for(int i = 1; i < n; i++) {
            if(i > right) {
                while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
                    Z[i]++;
                left = i;
                right = i + Z[i] - 1;
            }
            else {
                int k = i - left;
                if(Z[k] < right - i + 1)
                    Z[i] = Z[k];
                else {
                    Z[i] = right - i + 1;
                    while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
                        Z[i]++;
                    left = i;
                    right = i + Z[i] - 1;
                }
            }
        }
        return Z;
    }

public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;

        string combined = needle + "$" + haystack;
        vector<int> Z = computeZarray(combined);
        int m = needle.size();

        for(int i = m + 1; i < Z.size(); i++) {
            if(Z[i] == m)
                return i - (m + 1);  
        }
        return -1;
    }
};
