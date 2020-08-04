class Solution {
public:
    int maxProfit(vector<int>& prices) {  // no limitation to transaction times
        int minn = 0xffffff;
        int maxSum = 0, maxP = 0;
        for (int i = 0; i < prices.size(); i++) {
            minn = min(minn, prices[i]);
            maxP = max(maxP, (prices[i] - minn));
            if (i != prices.size() - 1 && prices[i] > prices[i+1]) {
                minn = 0xffffff;
                maxSum += maxP;
                maxP = 0;
            }
            if (i == prices.size() - 1) {
                maxSum += maxP;
            }
            
            // Or, simplest way is to divide total profit into daily sum: 
            // maxSum += max(prices[i] - prices[i - 1], 0);    
        }
        return maxSum;
    }
};