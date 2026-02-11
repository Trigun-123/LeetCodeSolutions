class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xs[0];
        int maxxXor = pow(2, maximumBit) - 1;

    nt i = 1; i < n; i++) {
            xorr ^= nums[i];
        }    
 {
            axxXor;
            ^= nums[n-1-i];
        }

        return result;
    }
};