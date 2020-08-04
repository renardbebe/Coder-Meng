class Solution {
public:
    int maxProfit(vector<int>& prices) {  // only one transaction
        int maxP = 0, minn = 0xffffff;
        for (int i = 0; i < prices.size(); i++) {
            minn = min(minn, prices[i]);
            maxP = max(maxP, (prices[i] -  minn));
        }
        return maxP;
    }
};