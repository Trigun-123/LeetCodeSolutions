class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result;

        for(int i = 0; i < n; i++) {
            if(nums[i][i] == '1') {
                result+= '0';
            }
            else {
                result += '1';
            }
        }
        
        return result;
    }
};