int dfs(vector<vector<int>>& matrix,int** &dp,int i,int j,int prev=INT_MIN){
    if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
        return 0;
    if(matrix[i][j]<=prev)
        return 0;
    if(dp[i][j]>-1)
        return dp[i][j];

    int op1=dfs(matrix,dp,i+1,j,matrix[i][j]);
    int op2=dfs(matrix,dp,i-1,j,matrix[i][j]);
    int op3=dfs(matrix,dp,i,j+1,matrix[i][j]);
    int op4=dfs(matrix,dp,i,j-1,matrix[i][j]);

    dp[i][j]=1+max(op1,max(op2,max(op3,op4)));

    return dp[i][j];
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int** dp=new int*[matrix.size()];
        for(int i=0;i<matrix.size();i++){
            dp[i]=new int[matrix[0].size()];
            for(int j=0;j<matrix[0].size();j++)
                dp[i][j]=-1;
        }
        
        int ans=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
                ans=max(ans,dfs(matrix,dp,i,j));
        }

        for(int i=0;i<matrix.size();i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};