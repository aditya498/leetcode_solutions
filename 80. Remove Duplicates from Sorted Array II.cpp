class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=0;
        int c=0;
        while (j<nums.size()){
            if(j==0) {
                c = 1;
                nums[i++]=nums[j++];
            }
            else if(nums[j]==nums[j-1]) {
                c += 1;
                if(c==2)
                    nums[i++]=nums[j++];
                else
                    j++;
            }
            else {
                c = 1;
                nums[i++]=nums[j++];
            }
        }
        return i;
    }
};