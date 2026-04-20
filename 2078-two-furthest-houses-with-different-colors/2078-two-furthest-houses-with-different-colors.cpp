class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), result = 0;

        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                result = max(result, i);
            }    
            if(colors[i] != colors[n-1]) {
                result = max(result, n-1-i);
            }
        }

        return result;
    }
};