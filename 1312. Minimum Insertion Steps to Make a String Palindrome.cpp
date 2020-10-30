int helper(string &str,int** &dp,int s,int e){
    if(s>e)
        return 0;
    if(dp[s][e]>-1)
        return dp[s][e];
    int ans=INT_MAX;
    if(str[s]==str[e])
        ans=helper(str,dp,s+1,e-1);
    else
        ans=1+min(helper(str,dp,s+1,e),helper(str,dp,s,e-1));
    dp[s][e]=ans;
    return ans;
}

class Solution {
public:
    int minInsertions(string str) {
        int** dp=new int*[str.size()];
        for(int i=0;i<str.size();i++){
            dp[i]=new int[str.size()];
            for(int j=0;j<str.size();j++)
                dp[i][j]=-1;
        }

        int ans=helper(str,dp,0,str.size()-1);

        for(int i=0;i<str.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};
