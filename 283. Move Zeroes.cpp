class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                zero++;
        }

        int i=0,j=0;
        while (j<nums.size()){
            if(nums[j]!=0)
                swap(nums[i++],nums[j]);
            j++;
        }

        int k=nums.size()-1;
        j=j-i;
        for(i=j;i>0;i--)
            nums[k--]=0;
    }
};