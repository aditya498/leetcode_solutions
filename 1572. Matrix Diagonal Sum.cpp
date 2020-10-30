class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++)
            ans+=mat[i][i];
        int k=mat.size()-1;
        for(int i=0;i<mat.size();i++)
            ans+=mat[i][k--];
        
        if(mat.size()%2!=0)
            ans=ans-mat[mat.size()/2][mat.size()/2];
        
        return ans;
    }
};