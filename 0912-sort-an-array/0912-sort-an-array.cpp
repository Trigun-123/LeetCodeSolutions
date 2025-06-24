class Solution {
private:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high;
        
        while(i < j) {
            while(nums[i] <= pivot && i <= high-1)
                i++;
            while(nums[j] > pivot && j >= low+1)
                j--;
            if(i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void qS(vector<int>& nums, int low, int high) {
        if(low < high) {
            int partitionIndex = partition(nums, low, high);
            qS(nums, low, partitionIndex-1);
            qS(nums, partitionIndex+1, high);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        qS(nums, low, high);
        return nums;
    }
};