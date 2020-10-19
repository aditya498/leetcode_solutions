int helper(vector<vector<int>>& grid,int** dp,int i,int j,int m,int n){
    if(i>=m || j>=n)
        return INT_MAX;
    if(i==m-1 && j==n-1)
        return grid[i][j];
    if(dp[i][j]>-1)
        return dp[i][j];

    dp[i][j]=grid[i][j]+min(helper(grid,dp,i+1,j,m,n),helper(grid,dp,i,j+1,m,n));

    return dp[i][j];
}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int** dp=new int*[m];
        for(int i=0;i<m;i++) {
            dp[i] = new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }

        int ans=helper(grid,dp,0,0,m,n);

        for(int i=0;i<m;i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};