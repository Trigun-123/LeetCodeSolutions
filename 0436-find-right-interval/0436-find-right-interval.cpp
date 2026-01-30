class Solution {  
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> nums;  
        
        for(int i = 0; i < n; i++) {
            nums.push_back({intervals[i][0], i});
        }
        
        sort(nums.begin(), nums.end());
        
        vector<int> result(n, -1);
        
        for(int i = 0; i < n; i++) {
            int endVal = intervals[i][1];
            int left = 0, right = n - 1, index = -1;

            while(left <= right) {
                int mid = (left + right) / 2;
                if(nums[mid].first >= endVal) {
                    index = nums[mid].second;  
                    right = mid - 1;           
                } 
                else {
                    left = mid + 1;
                }
            }
            
            result[i] = index;
        }
        
        return result;
    }
};