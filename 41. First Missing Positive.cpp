class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=0 || nums[i]>nums.size()){
                i++;
                continue;
            }
            if(nums[i]==i+1){
                i++;
                continue;
            }
            if(nums[nums[i]-1]==nums[i]){
                i++;
                continue;
            }
            swap(nums[i],nums[nums[i]-1]);
        }

        i=0;
        while (i<nums.size()){
            if(nums[i]!=i+1)
                return i+1;
            i++;
        }
        return nums.size()+1;
    }
};