class Solution {
private:
    int randomIndex(int &left, int &right) {
        int length = right - left + 1;
        return (rand() % length) + left;
    }

    int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right) {
        int pivot = nums[pivotIndex];
        swap(nums[left], nums[pivotIndex]);

        int ind = left + 1;

        for(int i = left + 1; i <= right; i++) {
            if(nums[i] > pivot) {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }
        swap(nums[left], nums[ind-1]);
        return ind-1;
    }

public:
    int kthLargestElement(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n)
            return -1;
         
        int left = 0, right = n - 1;
        
        while(true) {
            int pivotIndex = randomIndex(left, right);
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);
            
            if(pivotIndex == k-1)
                return arr[pivotIndex]; 
            else if(pivotIndex > k-1)
                right = pivotIndex - 1;
            else
                left = pivotIndex + 1;
        }
        return -1;
    }
};
