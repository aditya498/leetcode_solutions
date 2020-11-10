class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy=0;
        for(int i=0;i<nums.size();i++)
            xy=xy^nums[i];
        
        int flag=xy&(-xy);
        
        vector<int> ans(2,0);
        for(int i=0;i<nums.size();i++){
            if((flag&nums[i])==0)
                ans[0]=ans[0]^nums[i];
            else
                ans[1]=ans[1]^nums[i];
        }
        return ans;
    }
};