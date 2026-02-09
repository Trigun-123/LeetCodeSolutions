class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;

        for(autonums) {
            fin ^=  it;
        }

        int oper = 0;

        while(k || finalXor) {
            if((k % 2) != (finalXor % 2)) {
                operations++;
            }
            k /= 2;
            finalXor /= 2;
        }

        return operations;
    }
};
