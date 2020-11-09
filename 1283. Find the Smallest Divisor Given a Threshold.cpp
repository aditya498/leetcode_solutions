int helper(vector<int> nums,int d){
    int ans=0;
    for(int i=0;i<nums.size();i++)
        ans+=(nums[i]/d + (nums[i]%d!=0?1:0));
    return ans;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=0;
        int s=1,e=pow(10,6)+1;
        while (s<=e){
            int m=(s+e)/2;
            if(helper(nums,m)<=threshold){
                ans=m;
                e=m-1;
            } else
                s=m+1;
        }
        return ans;
    }
};