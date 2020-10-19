class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int minV=INT_MAX;
        while (s<=e){
            int m=(s+e)/2;
            minV=min(minV,min(nums[m],min(nums[s],nums[e])));
            if(nums[s]<nums[m])
                s=m+1;
            else
                e=m-1;
        }
        return minV;
    }
};