class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n - 1;

        while(left < right) {
            int mid = (left + right) / 2;
            int count = 0;

            for(auto it : nums) {
                if(it <= mid) {
                    count++;
                }
            }

            if(count > mid) {
                right = mid;
            } 
            else { 
                left = mid + 1;
            }
        }

        return left;
    }
};