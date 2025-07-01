class Solution {
private:
    bool binarySearch(vector<int>& nums, int target) {
        int n = nums.size(); 
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target)
                return true;
            else if(target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0; i < n; i++) {
            bool flag =  binarySearch(matrix[i], target);
            if(flag)
                return true;
        }
        return false; 
    }
};