class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> frequency;
        unordered_map<int, int> firstIndex;
        int minLength = INT_MAX, degree= 0;

        for(int i = 0; i < n; i++) {
            frequency[nums[i]]++;
            if(frequency[nums[i]] == 1) {
                firstIndex[nums[i]] = i;
            }   
		
            if(frequency[nums[i]] == degree) {
                int currLength = i - firstIndex[nums[i]] + 1;
                if(minLength > currLength) {
                    minLength = currLength;
                }    
            }   
        
            if(frequency[nums[i]] > degree) {
                minLength = i - firstIndex[nums[i]] + 1;
                degree = frequency[nums[i]];
            }    
        }
        
        return minLength;
    }
};