class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int r=matrix.size();
        int c=matrix[0].size();

        int** dp=new int*[r];
        for(int i=0;i<r;i++)
            dp[i]=new int[c]{0};

        for(int i=0;i<c;i++)
            dp[0][i]=matrix[0][i]-48;

        for(int i=0;i<r;i++)
            dp[i][0]=matrix[i][0]-48;

        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }

        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        for(int i=0;i<r;i++)
            delete[] dp[i];
        delete[] dp;

        return ans*ans;
    }
};