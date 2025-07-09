class Solution {
private:
    bool rabinKarp(const string& haystack, const string& needle, int base = 256, int mod = 1e9 + 7) {
        int m = needle.size(), n = haystack.size();
        if(m > n)
            return false;

        long long hash_needle = 0, hash_window = 0, power = 1;

        for(int i = 0; i < m - 1; ++i)
            power = (power * base) % mod;

        for(int i = 0; i < m; ++i) {
            hash_needle = (hash_needle * base + needle[i]) % mod;
            hash_window = (hash_window * base + haystack[i]) % mod;
        }

        for(int i = 0; i <= n - m; ++i) {
            if(hash_window == hash_needle) {
                if(haystack.substr(i, m) == needle)
                    return true;
            }

            if(i < n - m) {
                hash_window = (hash_window - haystack[i] * power % mod + mod) % mod;
                hash_window = (hash_window * base + haystack[i + m]) % mod;
            }
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        while(repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        if (rabinKarp(repeated, b))
            return count;

        repeated += a;
        count++;

        if(rabinKarp(repeated, b))
            return count;
        return -1;
    }
};
