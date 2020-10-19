class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int* dp=new int[n]{0};
        int min_price=INT_MAX;
        int max_profit=INT_MIN;
        
        for(int i=0;i<n;i++){
            min_price=min(prices[i],min_price);
            max_profit=max(max_profit,prices[i]-min_price);
            dp[i]=max_profit;
        }
        
        int max_price=INT_MIN;
        max_profit=INT_MIN;
        
        for(int i=n-1;i>=0;i--){
            max_price=max(max_price,prices[i]);
            max_profit=max(max_profit,max_price-prices[i]);
            dp[i]+=max_profit;
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        
        return ans;
    }
};