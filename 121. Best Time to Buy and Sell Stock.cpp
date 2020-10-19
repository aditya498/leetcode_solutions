class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int min_price=INT_MAX;
        for(int i=0;i<n;i++){
            min_price=min(min_price,prices[i]);
            ans=max(ans,prices[i]-min_price);
        }
        return ans;
    }
};