class Pair{
public:
    int buy;
    int sell;
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0)
            return 0;
        Pair* dp=new Pair[prices.size()];
        dp[0].buy=-1*prices[0];
        dp[0].sell=0;
        
        for(int i=1;i<prices.size();i++){
            dp[i].buy=max(dp[i-1].buy,dp[i-1].sell-prices[i]);
            dp[i].sell=max(dp[i-1].sell,dp[i-1].buy-fee+prices[i]);
        }
        
        int ans=dp[prices.size()-1].sell;
        delete[] dp;
        return ans;
    }
};