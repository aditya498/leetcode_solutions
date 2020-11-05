void helper(int s,int n,int k,vector<int> temp,vector<vector<int>> &ans){
    if(k==0){
        ans.push_back(temp);
        return;
    }

    for(int i=s;i<=n;i++){
        temp.push_back(i);
        helper(i+1,n,k-1,temp,ans);
        temp.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1,n,k,temp,ans);
        return ans;
    }
};