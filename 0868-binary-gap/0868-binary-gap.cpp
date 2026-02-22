class Solution {
public:
    int binaryGap(int n) {
        int maximumDistance = 0, currentDistance = 0;
        bool hasSeenFirstOne = false;
        
        while(n > 0) {
            int currentBit = n % 2;
            if(currentBit == 1) {
                if(hasSeenFirstOne) {
                    maximumDistance = max(maximumDistance, currentDistance);
                }
                currentDistance = 1;
                hasSeenFirstOne = true;
            } 
            else {
                if(hasSeenFirstOne) {
                    currentDistance++;
                }
            }
            
            n /= 2;
        }
        
        return maximumDistance;
    }
};