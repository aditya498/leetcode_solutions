int helper(string words1,string words2,int** dp){
    if(words1.size()==0)
        return words2.size();
    if(words2.size()==0)
        return words1.size();
    if(dp[words1.size()][words2.size()]>-1)
        return dp[words1.size()][words2.size()];
    
    if(words1[0]==words2[0])
        dp[words1.size()][words2.size()]=helper(words1.substr(1),words2.substr(1),dp);
    else
        dp[words1.size()][words2.size()]=1+min(helper(words1.substr(1),words2.substr(1),dp),min(helper(words1.substr(1),words2,dp),helper(words1,words2.substr(1),dp)));

    return dp[words1.size()][words2.size()];
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int** dp=new int*[word1.size()+1];
        for(int i=0;i<=word1.size();i++){
            dp[i]=new int[word2.size()+1];
            for(int j=0;j<=word2.size();j++)
                dp[i][j]=-1;
        }
        
        int ans=helper(word1,word2,dp);
        
        for(int i=0;i<=word1.size();i++)
            delete[] dp[i];
        delete[] dp;
        
        return ans;
    }
};