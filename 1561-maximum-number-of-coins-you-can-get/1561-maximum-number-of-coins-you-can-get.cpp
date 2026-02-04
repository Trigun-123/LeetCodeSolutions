class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int count = 0;

        for(int i = 0; i < piles.size() / 3; i++) {
            count += piles[n - 2];
            n -= 2;
        }
        
        return count;
    }
};