class Solution {
private:
    int countStudents(vector<int> &nums, int n, int maxSum) {
        int partitions = 1;
        int subArraySum = 0;

        for(int i = 0; i < n; i++) {
            if(subArraySum + nums[i] <= maxSum)
                subArraySum += nums[i];
            else {
                partitions++;
                subArraySum = nums[i];
            }    
        }
        return partitions;
    }

public:
    int splitArray(vector<int> &nums, int k)  {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(countStudents(nums, n, mid) > k)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};