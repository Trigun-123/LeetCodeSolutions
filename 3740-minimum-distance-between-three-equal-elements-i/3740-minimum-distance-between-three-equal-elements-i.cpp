class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX ;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[i] == nums[j]) {
                    for(int k = j+1; k < n; k++) {
                        if(nums[j] == nums[k]) {
                            result = min(result, 2*(k-i)) ;
                        }
                    }
                }
            }            
        }

        if(result == INT_MAX) {
            return -1 ;
        }    
        else {
            return result;
        }
    }
};