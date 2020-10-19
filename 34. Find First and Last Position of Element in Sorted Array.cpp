class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1;
        int end=-1;

        int l=0,r=nums.size()-1;
        while (l<=r){
            int m=(l+r)/2;
            if(nums[m]<target)
                l=m+1;
            else if(nums[m]>target)
                r=m-1;
            else{
                start=m;
                r=m-1;
            }
        }
        
        l=0,r=nums.size()-1;
        
        while (l<=r){
            int m=(l+r)/2;
            if(nums[m]<target)
                l=m+1;
            else if(nums[m]>target)
                r=m-1;
            else{
                end=m;
                l=m+1;
            }
        }
        
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;
    }
};