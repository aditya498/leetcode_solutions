void helper(vector<int> &nums,vector<vector<int>> &ans,int i,vector<int> temp){
    if(i==nums.size()){
        ans.push_back(temp);
        return;
    }
    
    helper(nums,ans,i+1,temp);
    temp.push_back(nums[i]);
    helper(nums,ans,i+1,temp);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(nums,ans,0,temp);
        return ans;
    }
};