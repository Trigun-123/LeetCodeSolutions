class Solution{
private:
    int firstOccurrence(vector<int>& nums, int n, int target) {
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return first;
    }

    int lastOccurrence(vector<int>& nums, int n, int target) {
        int low = 0;
        int high = n-1;
        int last = -1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) {
                last = mid;
                low = mid+1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return last;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        
        int first = firstOccurrence(nums, n, target);
        if(first == -1)
            return {-1, -1};
        int last = lastOccurrence(nums, n, target);
        return {first, last};
    }
};