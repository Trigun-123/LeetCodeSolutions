class Solution {
private:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int index1, int index2) {
        if(nums1[index1] > nums2[index2])
            swap(nums1[index1], nums2[index2]);
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int length = n + m;
        int gap = (length / 2) + (length % 2);

        while(gap > 0) {
            int left = 0;
            int right = left + gap;
            while(right < length) {
                if(left < m && right >= m)
                    swapIfGreater(nums1, nums2, left, right - m);
                else if(left >= m)
                    swapIfGreater(nums2, nums2, left - m, right - m);
                else
                    swapIfGreater(nums1, nums1, left, right);

                left++;
                right++;
            }
            if(gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }

        for(int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m]; 
    }
};