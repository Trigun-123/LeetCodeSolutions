class Solution {
private:
    void func(int index, vector<int> &arr, vector<int> &nums, vector<vector<int>> &result) {
        if(index == nums.size()) {
            result.push_back(arr);
            return;
        }
        arr.push_back(nums[index]);
        func(index+1, arr, nums, result);
        arr.pop_back();

        for(int j = index + 1; j < nums.size(); j++) {
            if(nums[j] != nums[index]) {
                func(j, arr, nums, result);
                return;
            }
        }
        func(nums.size(), arr, nums, result);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;  
        vector<int> arr;          
        sort(nums.begin(), nums.end()); 
        func(0, arr, nums, result);  
        return result; 
    }
};