class Solution {
   private:
    int findMax(vector<int> &nums, int n) {
        int maxx = INT_MIN;
        for(int i = 0; i < n; i++)
          maxx = max(maxx, nums[i]);
        return maxx;
    }

    int sumByD(vector<int> &nums, int n, int threshold) {
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += ceil((double)(nums[i]) / (double)(threshold));
        return sum;
    }

   public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int n = nums.size();
        if (n > threshold)
          return -1;
        int maxx = findMax(nums, n);
        int low = 1, high = maxx;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(sumByD(nums, n, mid) <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};