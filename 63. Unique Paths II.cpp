int helper(vector<vector<int>>& obstacleGrid,int** dp,int i,int j,int m,int n){
    if(i>=m || j>=n)
        return 0;
    if(obstacleGrid[i][j]==1)
        return 0;
    if(i==m-1 && j==n-1)
        return 1;
    if(dp[i][j]>-1)
        return dp[i][j];

    dp[i][j]=helper(obstacleGrid,dp,i+1,j,m,n)+helper(obstacleGrid,dp,i,j+1,m,n);
    return dp[i][j];
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int** dp=new int*[m];
        for(int i=0;i<m;i++) {
            dp[i] = new int[n];
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        }

        int ans=helper(obstacleGrid,dp,0,0,m,n);

        for(int i=0;i<m;i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};