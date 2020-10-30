class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0)
            return 0;
        
        vector<int> dp(ratings.size(),0);
        dp[0]=1;
        
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1])
                dp[i]=1+dp[i-1];
            else
                dp[i]=1;
        }
        
        int ans=dp[ratings.size()-1];
        
        for(int i=ratings.size()-2;i>=0;i--){
            if(ratings[i]>ratings[i+1] && dp[i]<=dp[i+1])
                dp[i]=1+dp[i+1];
            ans+=dp[i];
        }
        
        return ans;
    }
};
