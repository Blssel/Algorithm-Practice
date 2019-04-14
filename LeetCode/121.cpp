class Solution {
public:
  int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
    int minP = prices[0];
    int res = 0;
    for (int i = 0; i < prices.size(); i++) {
      res = max(res, prices[i] - minP);
      minP = min(prices[i], minP);
    }
    return res;
  }
};
