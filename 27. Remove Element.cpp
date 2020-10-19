class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        while (i<nums.size()){
            if(nums[i]!=val) 
                i++;
            else{
                if(j<i)
                    j=i+1;
                while(j<nums.size() && nums[j]==val)
                    j++;
                if(j==nums.size())
                    break;
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
        return i;
    }
};