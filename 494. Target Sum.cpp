class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=0;
        for(int i=0;i<nums.size();i++)
            s+=nums[i];
        
        if(target>s)
            return 0;
        
        int** dp=new int*[nums.size()];
        for(int i=0;i<nums.size();i++)
            dp[i]=new int[2*s+1]{0};

        dp[0][s+nums[0]]+=1;
        dp[0][s-nums[0]]+=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=2*s;j++){
                if(dp[i-1][j]!=0){
                    dp[i][j+nums[i]]+=dp[i-1][j];
                    dp[i][j-nums[i]]+=dp[i-1][j];
                }
            }
        }
        
        int ans=dp[nums.size()-1][s+target];

        for(int i=0;i<nums.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};