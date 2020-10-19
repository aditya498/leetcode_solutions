class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        if(k>=n/2){
            int ans=0;
            for(int i=0;i<n-1;i++){
                if(prices[i]<prices[i+1])
                    ans+=(prices[i+1]-prices[i]);
            }
            return ans;
        }
        
        int** dp=new int*[2];
        for(int i=0;i<2;i++)
            dp[i]=new int[n]{0};
        bool flag=1;
        for(int i=1;i<=k;i++){
            int maxV=INT_MIN;
            for(int j=1;j<n;j++){
                maxV=max(maxV,dp[flag^1][j-1]-prices[j-1]);
                dp[flag][j]=max(dp[flag][j-1],maxV+prices[j]);
            }
            flag=flag^1;
        }

        int ans=dp[flag^1][n-1];

        for(int i=0;i<2;i++)
            delete[] dp[i];
        delete[] dp;
        return ans;
    }
};
