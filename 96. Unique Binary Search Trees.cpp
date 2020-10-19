int helper(int* dp,int n){
    if(n==0)
        return 1;
    if(dp[n]>-1)
        return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=(helper(dp,i-1)*helper(dp,n-i));
    dp[n]=ans;
    return ans;
}

class Solution {
public:
    int numTrees(int n) {
        int* dp=new int[n+1];
        for(int i=0;i<n;i++)
            dp[i]=-1;
        int ans=helper(dp,n);
        delete[] dp;
        return ans;
    }
};