int helper(string str,string pat,int s,int e,int ps,int*** dp){
    if(s==e)
        return str[s]==pat[ps];
    if(str.substr(s,e-s+1)==pat.substr(ps,e-s+1))
        return 1;
    if(dp[s][e][ps]>-1)
        return dp[s][e][ps];

    int ans=0;
    for(int i=s;i<e;i++){
        int l=i-s;
        ans=(helper(str,pat,s,i,ps,dp)==1) && (helper(str,pat,i+1,e,ps+l+1,dp)==1);
        if(ans==1)
            break;
        ans=(helper(str,pat,e-l,e,ps,dp)==1) && (helper(str,pat,s,e-l-1,ps+l+1,dp)==1);
        if(ans==1)
            break;
    }
    dp[s][e][ps]=ans;

    return ans;
}

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<s1.size();i++) {
            freq1[s1[i]-97]++;
            freq2[s2[i]-97]++;
        }

        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])
                return false;
        }
        
        int n=s1.size();
        
        int*** dp=new int**[n];
        for(int i=0;i<n;i++){
            dp[i]=new int*[n];
            for(int j=0;j<n;j++){
                dp[i][j]=new int[n];
                for(int k=0;k<n;k++)
                    dp[i][j][k]=-1;
            }
        }

        int ans=helper(s1,s2,0,s1.size()-1,0,dp);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                delete[] dp[i][j];
            delete[] dp[i];
        }
        delete[] dp;

        return ans==1;
    }
};