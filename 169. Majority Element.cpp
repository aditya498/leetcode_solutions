class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=0;
        int count=0;
        int i=0;
        while (i<nums.size()){
            if(count==0)
                val=nums[i];
            if(nums[i]==val)
                count++;
            else
                count--;
            i++;
        }
        return val;
    }
};