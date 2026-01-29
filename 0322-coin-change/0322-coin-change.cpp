class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> minCoins(amount + 1, amount + 1);
        minCoins[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < n; j++) {
                if(i - coins[j] >= 0) {
                    minCoins[i] = min(minCoins[i], 1 + minCoins[i - coins[j]]);
                }
            }
        }

        if(minCoins[amount] != amount + 1) {
            return minCoins[amount];
        }

        return -1;        
    }
};