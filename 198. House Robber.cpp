class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int* dp=new int[nums.size()];
        dp[0]=nums[0];
        if(nums.size()>1)
            dp[1]=max(dp[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        
        int ans=dp[nums.size()-1];
        delete[] dp;
        return ans;
    }
};