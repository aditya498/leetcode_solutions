class Solution {
public:
    bool isMatch(string str, string pat) {
        bool** dp=new bool*[pat.size()+1];
        for(int i=0;i<=pat.size();i++)
            dp[i]=new bool[str.size()+1];

        for(int i=0;i<=str.size();i++)
            dp[0][i]=false;
        dp[0][0]=true;
        for(int i=1;i<=pat.size();i++){
            if(pat[i-1]=='*')
                dp[i][0]=dp[i-2][0];
            else
                dp[i][0]=false;
        }

        for(int i=1;i<=pat.size();i++){
            for(int j=1;j<=str.size();j++){
                int i_1=i-1;
                int j_1=j-1;
                if(pat[i_1]=='.' || pat[i_1]==str[j_1])
                    dp[i][j]=dp[i-1][j-1];
                else if(pat[i_1]=='*'){
                    dp[i][j]=dp[i-2][j];
                    if(dp[i][j]==false){
                        if(pat[i_1-1]=='.' || pat[i_1-1]==str[j_1])
                            dp[i][j]=dp[i][j-1];
                        else
                            dp[i][j]=false;
                    }
                } else
                    dp[i][j]=false;
            }
        }

        bool ans=dp[pat.size()][str.size()];

        for(int i=0;i<=pat.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};