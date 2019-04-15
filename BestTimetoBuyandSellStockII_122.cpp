class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minValue = prices[0], maxValue = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minValue) {
                maxProfit += maxValue - minValue;
                minValue = prices[i];
                maxValue = prices[i];
            } else {
                if (prices[i] < maxValue) {
                    maxProfit += maxValue - minValue;
                    minValue = prices[i];
                } 
                maxValue = prices[i];
            }      
        }
        maxProfit += maxValue - minValue;
        return maxProfit;
    }
};