class Solution {
public:
    int search(vector<int> &nums, int k) {
       int n = nums.size();
       int low = 0, high = n-1;

       while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == k)
                return mid;
            
            // left sorted
            if(nums[low] <= nums[mid]) {
                if(nums[low] <= k && k <= nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            // right sorted
            else {
                if(nums[mid] <= k && k <= nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};