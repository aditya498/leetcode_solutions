class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(i==0)
                ans.push_back(nums[i]);
            else
                ans.push_back(ans[i-1]*nums[i]);
        }
        int prod=1;
        for(int i=ans.size()-1;i>=0;i--){
            if(i==0)
                ans[i]=prod;
            else{
                ans[i]=prod*ans[i-1];
                prod*=nums[i];
            }
        }
        return ans;
    }
};