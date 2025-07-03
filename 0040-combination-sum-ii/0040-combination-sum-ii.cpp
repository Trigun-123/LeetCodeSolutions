class Solution {
private: 
    void func(int ind, int sum, vector<int> &nums, vector<int> &candidates, vector<vector<int>> &result) {
        if(sum == 0) {
            result.push_back(nums);
            return;
        }
        if(sum < 0 || ind == candidates.size())
            return; 
        nums.push_back(candidates[ind]); 
        func(ind + 1, sum - candidates[ind], nums, candidates, result); 
        nums.pop_back(); 
        for(int i = ind + 1; i < candidates.size(); i++) {
            if(candidates[i] != candidates[ind]) {
                func(i, sum, nums, candidates, result); 
                break; 
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        vector<int> nums; 
        sort(candidates.begin(), candidates.end()); 
        func(0, target, nums, candidates, result);
        return result; 
    }
};