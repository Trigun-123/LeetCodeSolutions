class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0;
        int result = 0;

        for(auto it : s) {
            if(it == 'b') {
                b++;
            }    
            else if(b) {
                result++;
                b--;
            }
        }

        return result;
    }
};