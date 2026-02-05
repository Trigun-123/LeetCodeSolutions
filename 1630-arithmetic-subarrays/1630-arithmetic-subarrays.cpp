class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int difference = arr[1] - arr[0];
        
        for(int i = 2; i < n; i++) {
            if(arr[i] - arr[i - 1] != difference) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> result;
        
        for(int i = 0; i < n; i++) {
            vector<int>in(nums) + l[i], begin(nums) + r[i] + 1);
            re.pack(func(arr));
        }
        
        return result;
    }
};
