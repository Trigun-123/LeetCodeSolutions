class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;

        for(int i = n; i > 1; i--) {
            int index = find(arr.begin(), arr.end(), i) - arr.begin();
            if(index == i - 1) {
                continue;
            }    
            if(index != 0) {
                reverse(arr.begin(), arr.begin() + index + 1);
                result.push_back(index + 1);
            }
            reverse(arr.begin(), arr.begin() + i);
            result.push_back(i);
        }

        return result;
    }
};