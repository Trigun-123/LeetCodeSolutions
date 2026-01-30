class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = MIN, sell = 0;

        for(int i = 0; i < n; i++) {
            buy = ax(buy, se - prices[i]);
            sell = max(sl, buy + prices[i] - fee);
        }

        return sell;
    }
};