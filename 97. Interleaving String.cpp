int helper(string s1,string s2,string s3,int*** dp){
    if(s1.size()==0 && s2.size()==0 && s3.size()==0)
        return 1;
    if(s1.size()==0 && s2.size()==0 && s3.size()!=0)
        return 0;
    if((s1.size()!=0 || s2.size()!=0) && s3.size()==0)
        return 0;
    if(dp[s1.size()][s2.size()][s3.size()]>-1)
        return dp[s1.size()][s2.size()][s3.size()];

    dp[s1.size()][s2.size()][s3.size()]=0;
    if(s1.size()!=0 && s1[0]==s3[0])
        dp[s1.size()][s2.size()][s3.size()]=dp[s1.size()][s2.size()][s3.size()] || helper(s1.substr(1),s2,s3.substr(1),dp);
    if(s2.size()!=0 && dp[s1.size()][s2.size()][s3.size()]!=1 && s2[0]==s3[0])
        dp[s1.size()][s2.size()][s3.size()]=dp[s1.size()][s2.size()][s3.size()] || helper(s1,s2.substr(1),s3.substr(1),dp);

    return dp[s1.size()][s2.size()][s3.size()];
}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int***dp=new int**[s1.size()+1];
        for(int i=0;i<=s1.size();i++){
            dp[i]=new int*[s2.size()+1];
            for(int j=0;j<=s2.size();j++){
                dp[i][j]=new int[s3.size()+1];
                for(int k=0;k<=s3.size();k++)
                    dp[i][j][k]=-1;
            }
        }

        int ans=helper(s1,s2,s3,dp);

        for(int i=0;i<=s1.size();i++){
            for(int j=0;j<=s2.size();j++)
                delete[] dp[i][j];
            delete[] dp[i];
        }
        delete[] dp;

        return ans==1;
    }
};