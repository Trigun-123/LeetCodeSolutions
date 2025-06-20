class Solution {
public:
    string largestOddNumber(string num) {
       int n = num.size();
       int j = -1;

        for(int i = n-1 ; i >= 0; i--) {
            if((num[i] - '0') % 2 == 1) {
                j = i;
                break;
            }
        }

        if(j == -1)
            return "";

        int i = 0;
        while(i < n) {
            if(num[i] != '0')
                break;
            i++;
        }
        return num.substr(i, j-i+1);
    }
};