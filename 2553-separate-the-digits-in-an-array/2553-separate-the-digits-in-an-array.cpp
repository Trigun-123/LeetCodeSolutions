class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for(auto it : nums) {
            string s = to_string(it);

            for(auto it : s) {
                result.push_back(it - '0');
            }
        }

        return result;
    }
};