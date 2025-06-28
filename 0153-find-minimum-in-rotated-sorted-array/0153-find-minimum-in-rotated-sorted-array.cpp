class Solution {
public:
    int findMin(vector<int> &nums)  {
        int n = nums.size();
        int low = 0, high = n-1;
        int minimum = INT_MAX;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[low] <= nums[high]) {
                minimum = min(minimum, nums[low]);
                break;
            }

            if(nums[low] <= nums[mid]) {
                minimum = min(minimum, nums[low]);
                low = mid+1;
            }
            else {
                high = mid-1;
                minimum = min(minimum, nums[mid]);
            }
        }
        return minimum;
    }
};