class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int low = 0, high = 0, blanks = 0;

        for(auto it : moves) {
            if(it == 'L') {
                low++;
            }    
            else if(it == 'R') {
                high++;
            }    
            else {
                blanks++;
            }    
        }

        int result = abs(low - high) + blanks;

        return result;
    }
};