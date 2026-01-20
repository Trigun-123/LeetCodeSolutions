class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;

        for(auto it : nums) {
            if(it % 2 == 0) {
                result.push_back(-1);
            }
            else {
                int i = 0;
                while(it & (1 << i)) {
                    i++;
                }    
                result.push_back(it ^ (1 << (i- 1)));
            }
        }

        return result;
    }
};