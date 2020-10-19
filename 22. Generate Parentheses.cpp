void helper(int opRem,int clRem,vector<string> &ans,string temp){
    if(opRem==0 && clRem==0){
        ans.push_back(temp);
        return;
    }

    if(opRem!=0)
        helper(opRem-1,clRem+1,ans,temp+"(");
    if(clRem!=0)
        helper(opRem,clRem-1,ans,temp+")");
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        helper(n,0,ans,temp);
        return ans;
    }
};