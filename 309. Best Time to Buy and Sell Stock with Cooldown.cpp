class Pair{
public:
    int buy;
    int sell;
    int cool;
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        
        Pair* dp=new Pair[prices.size()];
        dp[0].buy=-1*prices[0];
        dp[0].sell=0;
        dp[0].cool=0;
        for(int i=1;i<prices.size();i++){
            dp[i].buy=max(dp[i-1].buy,dp[i-1].cool-prices[i]);
            dp[i].sell=max(dp[i-1].sell,dp[i-1].buy+prices[i]);
            dp[i].cool=max(dp[i-1].cool,dp[i-1].sell);
        }
        
        int ans=dp[prices.size()-1].sell;
        delete[] dp;
        
        return ans;
    }
};