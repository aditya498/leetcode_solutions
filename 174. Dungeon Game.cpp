int helper(vector<vector<int>>& matrix,int r,int c,int** dp,int i,int j){
    if(i>=r || j>=c)
        return INT_MAX;
    if(i==r-1 && j==c-1){
        return 1+max(0,-1*matrix[i][j]);
    }
    if(dp[i][j]!=INT_MAX)
        return dp[i][j];
    int op1=helper(matrix,r,c,dp,i+1,j);
    int op2=helper(matrix,r,c,dp,i,j+1);
    int req=min(op1,op2)-matrix[i][j];
    dp[i][j]=max(1,req);
    return dp[i][j];
}

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size()==0)
            return -1;
        int r=dungeon.size();
        int c=dungeon[0].size();
        int** dp=new int*[r];
        for(int i=0;i<r;i++){
            dp[i]=new int[c];
            for(int j=0;j<c;j++)
                dp[i][j]=INT_MAX;
        }

        int ans=helper(dungeon,r,c,dp,0,0);

        for(int i=0;i<r;i++)
            delete[] dp[i];
        delete[] dp;

        return ans;
    }
};