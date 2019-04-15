class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) 
            return 0;
        
        int maxProfit = 0, minValue = prices[0], tmp;
        for (int i = 1; i < prices.size(); ++i){
            if (prices[i] < minValue) {
                minValue = prices[i];
            } else {
                tmp = prices[i] - minValue;
                if (tmp > maxProfit)
                    maxProfit = tmp;     
            }
        }
        return maxProfit;  
    }
};