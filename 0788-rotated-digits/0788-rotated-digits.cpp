class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        
        for(int i = 1; i <= n; i++) {
            int check = i;
            bool val = true, change = false;

            while(check > 0 && val) {
                int digit = check % 10;

                if(digit == 3 ||  digit == 4 || digit == 7) {
                    val = false;
                }    
                else if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                    change = true;
                }
               
                check /= 10;
            }
            
            if(val && change) {
                count++;
            }    
        }
       
        return count;
    }
};