class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        bool valley=false;
        int n=prices.size();
        if(n==1)
            return ans;
        for(int i=0;i<n;i++){
            if(i==0){
                if(prices[i]<=prices[i+1]){
                    valley=true;
                    ans=ans-prices[i];
                }
            } else if(i==n-1){
                if(valley && prices[i]>=prices[i-1]){
                    valley= false;
                    ans=ans+prices[i];
                }
            } else{
                if(!valley && prices[i-1]>=prices[i] && prices[i]<=prices[i+1]){
                    valley=true;
                    ans=ans-prices[i];
                } else if(valley && prices[i-1]<=prices[i] && prices[i]>=prices[i+1]){
                    valley= false;
                    ans=ans+prices[i];
                }
            }
        }
        return ans;
    }
};