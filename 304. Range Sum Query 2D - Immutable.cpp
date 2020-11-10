class NumMatrix {
private:
    int** dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp=new int*[matrix.size()];
        for(int i=0;i<matrix.size();i++)
            dp[i]=new int[matrix[0].size()]{0};

        int s=0;
        if(matrix.size()!=0){
            for(int i=0;i<matrix[0].size();i++){
                s+=matrix[0][i];
                dp[0][i]=s;
            }
        }

        for(int i=1;i<matrix.size();i++){
            s=0;
            for(int j=0;j<matrix[0].size();j++){
                s+=matrix[i][j];
                dp[i][j]=s+dp[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=dp[row2][col2];
        if(col1-1>=0)
            ans=ans-dp[row2][col1-1];
        if(row1-1>=0)
            ans=ans-dp[row1-1][col2];
        if(row1-1>=0 && col1-1>=0)
            ans=ans+dp[row1-1][col1-1];
        return ans;
    }
};