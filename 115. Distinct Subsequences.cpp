class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.size()==0 || s.size()==0)
            return 0;
        long long** dp=new long long*[t.size()];
        for(int i=0;i<t.size();i++)
            dp[i]=new long long[s.size()]{0};

        dp[0][0]=s[0]==t[0];
        for(int i=1;i<s.size();i++){
            if(t[0]==s[i])
                dp[0][i]=dp[0][i-1]+1;
            else
                dp[0][i]=dp[0][i-1];
        }

        for(int i=1;i<t.size();i++){
            for(int j=1;j<s.size();j++){
                if(t[i]==s[j])
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }

        int ans=dp[t.size()-1][s.size()-1];

        for(int i=0;i<t.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};
