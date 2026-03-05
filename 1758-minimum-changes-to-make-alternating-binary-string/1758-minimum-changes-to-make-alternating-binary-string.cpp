class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count1 = 0, count2 = 0;
        int last1 = '0', last2 = '1';
        
        for(int i = 0; i < n; i++) {
            if(s[i] != last1) {
                count1++;
            }
            if(s[i] != last2) {
                count2++;
            }
            
            swap(last1, last2);
        }

        return min(count1, count2);
    }
};