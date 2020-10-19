class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        int val=INT_MAX;
        while (s<=e){
            int m=(s+e)/2;
            val=min(min(val,nums[m]),min(nums[s],nums[e]));
            if(nums[s]<nums[m])
                s=m+1;
            else if(nums[m]<nums[e])
                e=m-1;
            else
                e--;
        }
        return val;
    }
};