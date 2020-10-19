class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(cur_sum>=0)
                cur_sum+=nums[i];
            else
                cur_sum=nums[i];
            ans=max(ans,cur_sum);
        }
        return ans;
    }
};