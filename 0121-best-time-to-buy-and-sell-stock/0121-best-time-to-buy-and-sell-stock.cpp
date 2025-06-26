class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int maximumProfit = 0;
        int bestBuy = prices[0];

        for(int i = 1; i <= n-1; i++) {
            if(prices[i] > bestBuy)
                maximumProfit = max(maximumProfit, prices[i] - bestBuy);
            bestBuy = min(bestBuy, prices[i]);
        }
        return maximumProfit;
    }
};