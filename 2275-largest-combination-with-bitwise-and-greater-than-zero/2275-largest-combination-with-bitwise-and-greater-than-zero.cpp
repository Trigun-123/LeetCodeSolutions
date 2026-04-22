class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int result = 0;

        for(int i = 0; i < 32; i++) {
            int count = 0;
            for(auto it : candidates) {
                if(it & (1<<i)) {
                    count++;
                }    
            }
            result = max(result, count);
        }

        return result;
    }
};