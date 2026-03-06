class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i = 0;

        while(s[i] == '1') {
            i++;
        }  

        if(i == n) {
            return 1;
        }

        int j = n - 1;

        while(s[j] == '0') {
            j--;
        }

        return i > j;
    }
};