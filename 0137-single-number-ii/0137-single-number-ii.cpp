class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n = nums.size();
        int bucket1 = 0, bucket2 = 0;
        
        for(int i=0; i < n; i++) {
            bucket1 = (bucket1 ^ nums[i]) & ~bucket2;
            bucket2 = (bucket2 ^ nums[i]) & ~bucket1;
        }
        return bucket1;
    }
};