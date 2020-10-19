class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int* dp=new int[nums.size()]{0};
        int ans=1;
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j] && dp[i]<dp[j])
                    dp[i]=dp[j];
            }
            dp[i]=1+dp[i];
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};