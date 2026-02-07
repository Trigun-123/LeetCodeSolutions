
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> frequency(n + 1);
        vector<vector<int>> result;

        for(auto it : nums) {
            if(frequency[it] >= result.size()) {
                result.push_back({});
            }
            result[frequency[it]].push_back(it);
            frequency[it]++;
        }
        
        return result;
    }
};


