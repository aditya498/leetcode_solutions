class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int* dp=new int[amount+1];
        for(int i=0;i<=amount;i++)
            dp[i]=amount+1;

        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        int ans=dp[amount];
        delete[] dp;
        if(ans>amount)
            return -1;
        return ans;
    }
};