class Solution {
private:
    void func(int index, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &result) {
        if(index == n) {
            result.push_back(arr);
            return;
        }
        func(index + 1, n, nums, arr, result);
        arr.push_back(nums[index]);
        func(index + 1, n, nums, arr, result);
        arr.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> arr; 
        func(0, nums.size(), nums, arr, result);  
        return result;  
    }
};