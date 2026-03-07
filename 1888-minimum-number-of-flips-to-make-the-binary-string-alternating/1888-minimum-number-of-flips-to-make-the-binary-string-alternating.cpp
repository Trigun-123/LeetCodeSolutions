class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int result = n;
        int operation[2] = {0, 0};

        for(int i = 0; i < n; i++) {
            operation[(s[i] ^ i) & 1]++;
        }    

        for(int i = 0; i < n; i++) {
            operation[(s[i] ^ i) & 1]--;
            operation[(s[i] ^ (n + i)) & 1]++;
            result = min(result, min(operation[0], operation[1]));
        }

        return result;
    }
};