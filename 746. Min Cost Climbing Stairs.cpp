int helper(vector<int>& cost,int* dp,int n,int i){
    if(i==n-1)
        return cost[i];
    if(i==n)
        return 0;
    if(dp[i]>-1)
        return dp[i];
    dp[i]=cost[i]+min(helper(cost,dp,n,i+1),helper(cost,dp,n,i+2));
    return dp[i];
}

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int* dp=new int[cost.size()];

        int ans=INT_MAX;
        for(int i=0;i<=1;i++){
            for(int i=0;i<cost.size();i++)
                dp[i]=-1;
            ans=min(ans,helper(cost,dp,cost.size(),i));
        }
        delete[] dp;
        return ans;
    }
};