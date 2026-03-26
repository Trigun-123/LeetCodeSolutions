class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int temp = 0;

        unordered_map<char, int> mpp = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for(int i = 0; i < n - 1; i++) {
            if(mpp[s[i]] < mpp[s[i + 1]]) {
                temp -= mpp[s[i]];
            } 
            else {
                temp += mpp[s[i]];
            }
        }

        int result = temp + mpp[s[n-1]];

        return result;        
    }
};