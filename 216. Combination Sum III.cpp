void helper(int sum,int n,int s,vector<int> temp,vector<vector<int>> &ans){
    if(n==0 && sum==0){
        ans.push_back(temp);
        return;
    }
    if(n==0 || sum<=0 || s>9)
        return;
    
    helper(sum,n,s+1,temp,ans);
    temp.push_back(s);
    helper(sum-s,n-1,s+1,temp,ans);
}

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n,k,1,temp,ans);
        return ans;
    }
};