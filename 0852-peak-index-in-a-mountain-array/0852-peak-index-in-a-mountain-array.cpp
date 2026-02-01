class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, result = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                result = mid;
                break;
            }
            else if(arr[mid] > arr[mid+1]) {
                high = mid;
            }    
            else if(arr[mid] > arr[mid-1]) {
                low = mid;
            }    
        }

        return result;
    }
};