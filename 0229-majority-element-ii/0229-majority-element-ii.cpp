class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(result.size() == 0 || result[0] != nums[i]) {
                int count = 0;
                for(int j = 0; j < n; j++) {
                    if(nums[j] == nums[i])
                        count++;
                }
                if(count > (n / 3))
                    result.push_back(nums[i]);
            }
            if(result.size() == 2)
                break;
        }
        return result;
    }
};