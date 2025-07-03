class Solution {
private: 
    void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &result) {
        if(sum == 0 && nums.size() == k) {
            result.push_back(nums);
            return; 
        }
        if(sum <= 0 || nums.size() > k)
            return; 
        for(int i = last; i <= 9; i++) {
            if(i <= sum) {
                nums.push_back(i); 
                func(sum - i, i + 1, nums, k, result); 
                nums.pop_back(); 
            }
            else 
                break;
        }        
    } 
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result; 
        vector<int> nums; 
        func(n, 1, nums, k, result);
        return result; 
    }
};