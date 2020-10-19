class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        while (s<=e){
            int m=(s+e)/2;
            if(nums[m]==target || nums[s]==target || nums[e]==target)
                return true;
            if(nums[s]<nums[m]){
                if(target<nums[m] && nums[s]<=target)
                    e=m-1;
                else
                    s=m+1;
            } else if(nums[m]<nums[e]){
                if(target>nums[m] && target<=nums[e])
                    s=m+1;
                else
                    e=m-1;
            } else
                e--;
        }
        return false;
    }
};