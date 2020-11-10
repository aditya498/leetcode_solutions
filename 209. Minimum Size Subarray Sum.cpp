class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0,r=0;
        int sum=0,ans=INT_MAX;
        while (r<=nums.size() && l<=r){
            if(sum>=s){
                ans=min(ans,r-l);
                sum-=nums[l++];
            } else{
                if(r==nums.size())
                    break;
                sum+=nums[r++];
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};