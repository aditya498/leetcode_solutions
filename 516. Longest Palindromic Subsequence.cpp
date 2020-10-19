int helper(string &str,int** &dp,int s,int e){
    if(s==e)
        return 1;
    if(s>e)
        return 0;
    if(dp[s][e]>-1)
        return dp[s][e];
    int ans=0;
    if(str[s]==str[e])
        ans=2+helper(str,dp,s+1,e-1);
    else
        ans=max(helper(str,dp,s,e-1),helper(str,dp,s+1,e));
    dp[s][e]=ans;
    return ans;
}

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int** dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }
        
        int ans=helper(s,dp,0,n-1);
        
        for(int i=0;i<n;i++)
            delete[] dp[i];
        delete[] dp;
        
        return ans;
    }
};