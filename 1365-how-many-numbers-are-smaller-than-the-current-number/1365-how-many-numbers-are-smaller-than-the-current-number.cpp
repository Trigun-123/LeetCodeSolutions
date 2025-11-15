class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101, 0);
        vector<int> result;

        for(auto it : nums) {   
            freq[it]++;
        }

        for(int i = 1; i < 101; i++) {
            freq[i] += freq[i-1];
        }

        result.reserve(n);

        for(int it : nums) {
            if(it == 0) 
                result.push_back(0);
            else
                result.push_back(freq[it-1]);
        }

        return result;
    }
};