int helper(int* dp,int n){
    if(n==0 || n==1)
        return n;
    if(dp[n]>0)
        return dp[n];
    dp[n]=helper(dp,n-1)+helper(dp,n-2);
    return dp[n];
}

class Solution {
public:
    int fib(int n) {
        int* dp=new int[n+1]{0};
        int ans=helper(dp,n);
        delete[] dp;
        return ans;
    }
};
