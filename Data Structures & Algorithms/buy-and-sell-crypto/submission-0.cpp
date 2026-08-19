class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 100;
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min) min = prices[i];
            if(prices[i] - min > ans) ans = prices[i] - min;
        }
        if(ans <= 0) return 0;
        else return ans;

    }
};
