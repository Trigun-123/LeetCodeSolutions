class Solution{	
public:		
	vector<int> singleNumber(vector<int>& nums){
        int n = nums.size();
		long XOR = 0;

        for(int i = 0; i < n; i++)
            XOR ^= nums[i];

        int rightmost = (XOR & (XOR - 1)) ^ XOR;
        int bucket1 = 0, bucket2 = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] & rightmost)
                bucket1 ^= nums[i];
            else
                bucket2 ^= nums[i];
        } 
        if(bucket1 < bucket2)
            return {bucket1, bucket2};
        else
            return {bucket2, bucket1};
	}
};