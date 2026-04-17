class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
        
        int n = s.length();
        string result = "";

        for(int i = 0; i < numRows; i++) {
            int multiply = (numRows-1) * 2;

            for(int j = i; j < n; j += multiply) {
                result += s[j];
                if(i > 0 && i < numRows-1 && (j+multiply-2*i < n)) {
                    result += s[j+multiply-2*i];
                }
            }
        }
        
        return result;
    }
};