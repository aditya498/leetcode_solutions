class Solution {
public:
    bool isMatch(string str, string pattern) {
        bool** dp=new bool*[pattern.size()+1];
        for(int i=0;i<=pattern.size();i++)
            dp[i]=new bool[str.size()+1];

        for(int i=str.size();i>=0;i--)
            dp[pattern.size()][i]=false;
        dp[pattern.size()][str.size()]=true;

        for(int i=pattern.size()-1;i>=0;i--){
            if(pattern[i]=='*')
                dp[i][str.size()]=dp[i+1][str.size()];
            else
                dp[i][str.size()]=false;
        }
        
        
        for(int i=pattern.size()-1;i>=0;i--){
            for(int j=str.size()-1;j>=0;j--){
                if(pattern[i]=='?')
                    dp[i][j]=dp[i+1][j+1];
                else if(pattern[i]=='*')
                    dp[i][j]=dp[i+1][j] || dp[i][j+1];
                else if(pattern[i]==str[j])
                    dp[i][j]=dp[i+1][j+1];
                else
                    dp[i][j]=false;
            }
        }
        
        bool ans=dp[0][0];
        
        for(int i=0;i<=pattern.size();i++)
            delete[] dp[i];
        delete[] dp;
        
        return ans;
    }
};