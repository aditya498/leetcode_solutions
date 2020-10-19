void helper(vector<int> &nums,vector<vector<int>> &ans,vector<bool> visited,vector<int> temp){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=0;i<nums.size();i++){
        if(visited[i])
            continue;
        visited[i]=true;
        temp.push_back(nums[i]);
        helper(nums,ans,visited,temp);
        temp.pop_back();
        visited[i]=false;
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visited(nums.size());
        for(int i=0;i<nums.size();i++)
            visited[i]=false;
        vector<int> temp;
        helper(nums,ans,visited,temp);
        
        return ans;
    }
};