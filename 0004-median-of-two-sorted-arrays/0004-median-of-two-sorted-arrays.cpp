class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int ind1 = (n - 1) / 2;
        int ind2 = n / 2;

        int i = 0, j = 0, cnt = 0;
        int curr = 0, prev = 0;

        while (i < n1 || j < n2) {
            prev = curr;

            if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }

            if (cnt == ind2) {
                if (n % 2 == 1) return curr;
                return (prev + curr) / 2.0;
            }

            cnt++;
        }

        return 0.0; // fallback, should never reach here
    }
};
