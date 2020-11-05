void helper(vector<int> nums,int s,vector<int> temp,vector<vector<int>> &ans){
    ans.push_back(temp);
        
    for(int i=s;i<nums.size();i++){
        if(i!=s && nums[i]==nums[i-1])
            continue;
        temp.push_back(nums[i]);
        helper(nums,i+1,temp,ans);
        temp.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        helper(nums,0,temp,ans);
        return ans;
    }
};