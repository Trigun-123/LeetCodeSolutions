class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0;
        int oddCount = 0;

        for(auto it : position) {
            if(it % 2 == 0) {
                evenCount++;
            }
            else {
                oddCount++;
            }
        }

        return min(oddCount, evenCount);
    }
};