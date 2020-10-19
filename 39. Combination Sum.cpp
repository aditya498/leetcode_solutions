vector<vector<int>> helper(vector<int>& candidates, int target,int i) {
    vector<vector<int>> ans;
    if(target<0 || i==candidates.size())
        return ans;

    if(target-candidates[i]==0){
        vector<int> temp;
        temp.push_back(candidates[i]);
        ans.push_back(temp);
        return ans;
    }

    vector<vector<int>> op1=helper(candidates,target,i+1);
    vector<vector<int>> op2=helper(candidates,target-candidates[i],i);

    for(int j=0;j<op1.size();j++){
        vector<int> temp;
        for(int k=0;k<op1[j].size();k++)
            temp.push_back(op1[j][k]);
        ans.push_back(temp);
    }

    for(int j=0;j<op2.size();j++){
        vector<int> temp;
        temp.push_back(candidates[i]);
        for(int k=0;k<op2[j].size();k++)
            temp.push_back(op2[j][k]);
        ans.push_back(temp);
    }

    return ans;
}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return helper(candidates,target,0);
    }
};