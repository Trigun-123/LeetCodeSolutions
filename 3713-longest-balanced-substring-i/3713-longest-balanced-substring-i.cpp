class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            a[i] = s[i] - 'a';
        }    

        int result = 0;

        for(int l = 0; l < n; l++) {
            if(n - l <= result) {
                break;
            }
            int count[26] = {0};
            int unique = 0, maxfreq = 0;

            for(int r = l; r < n; r++) {
                int i = a[r];
                if(count[i] == 0) {
                    unique++;
                }    
                count[i]++;

                if(count[i] > maxfreq) {
                    maxfreq = count[i];
                }    
                int current = r - l + 1;

                if(unique * maxfreq == current && current > result) {
                    result = current;
                }    
            }
        }
        
        return result;
    }
};
