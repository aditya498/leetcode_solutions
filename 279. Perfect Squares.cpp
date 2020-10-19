int helper(int* dp,int n){
    if(n<=0)
        return 0;
    if(dp[n]>0)
        return dp[n];
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++)
        ans=min(ans,helper(dp,n-i*i));
    dp[n]=1+ans;
    return dp[n];
}

class Solution {
public:
    int numSquares(int n) {
        int* dp=new int[n+1]{0};
        int ans=helper(dp,n);
        delete[] dp;
        return ans;
    }
};