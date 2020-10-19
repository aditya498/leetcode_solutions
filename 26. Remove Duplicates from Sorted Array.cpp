class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=INT_MAX;
        int e=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(prev!=nums[i]){
                nums[e++]=nums[i];
                prev=nums[i];
            }
        }
        while(e<=n-1){
            e++;
            nums.pop_back();
        }
        return nums.size();
    }
};