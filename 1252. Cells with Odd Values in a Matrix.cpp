class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(n,vector<int>(m,0));
        for(int i=0;i<indices.size();i++){
            for(int j=0;j<m;j++)
                matrix[indices[i][0]][j]++;
            for(int j=0;j<n;j++)
                matrix[j][indices[i][1]]++;
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                ans+=(matrix[i][j]%2!=0?1:0);
        }
        return ans;
    }
};