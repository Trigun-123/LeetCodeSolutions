class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        int duplicateNumber = -1;
        int missingNumber = -1;

        for(auto it : nums) {
            freq[it]++;
        }

        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2) 
                duplicateNumber = i;
            if(freq[i] == 0)
                missingNumber = i;
        }

        return {duplicateNumber, missingNumber};
    }
};