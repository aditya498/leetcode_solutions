int helper(string str,int n,int* dp){
    if(n==0)
        return 1;
    if(str[0]-48==0)
        return 0;
    if(dp[n]>-1)
        return dp[n];

    int ans=0;
    ans=helper(str.substr(1),n-1,dp);
    if(n>=2){
        int num=(str[0]-48)*10+(str[1]-48);
        if(num<=26)
            ans+=helper(str.substr(2),n-2,dp);
    }
    dp[n]=ans;
    return ans;
}

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int* dp=new int[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        int ans=helper(s,n,dp);
        delete[] dp;
        return ans;
    }
};