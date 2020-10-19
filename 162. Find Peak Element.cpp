class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        if(nums.size()==1)
            return 0;
        while (s<=e){
            int m=(s+e)/2;
            if(m==0 && nums[m]>nums[m+1])
                return m;
            if(m==nums.size()-1 && nums[m]>nums[m-1])
                return m;
            if(m!=0 && m!=nums.size()-1 && nums[m]>nums[m-1] && nums[m]>nums[m+1])
                return m;
            if(nums[m]<nums[m+1])
                s=m+1;
            else
                e=m-1;
        }
        return -1;
    }
};