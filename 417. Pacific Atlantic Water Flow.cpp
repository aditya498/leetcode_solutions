void dfs(vector<vector<int>> &matrix,bool** visited,int r,int c,int i,int j,int prev=INT_MIN){
    if(i<0 || j<0 || i>=r || j>=c || visited[i][j] || prev>matrix[i][j])
        return;
    visited[i][j]=true;
    dfs(matrix,visited,r,c,i+1,j,matrix[i][j]);
    dfs(matrix,visited,r,c,i-1,j,matrix[i][j]);
    dfs(matrix,visited,r,c,i,j+1,matrix[i][j]);
    dfs(matrix,visited,r,c,i,j-1,matrix[i][j]);
}

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int r=matrix.size();
        vector<vector<int>> ans;
        if(r==0)
            return ans;
        int c=matrix[0].size();

        bool** pac_vis=new bool*[r];
        bool** atl_vis=new bool*[r];
        for(int i=0;i<r;i++){
            pac_vis[i]=new bool[c]{0};
            atl_vis[i]=new bool[c]{0};
        }

        for(int i=0;i<c;i++)
            dfs(matrix,pac_vis,r,c,0,i);
        for(int i=0;i<r;i++)
            dfs(matrix,pac_vis,r,c,i,0);

        for(int i=0;i<c;i++)
            dfs(matrix,atl_vis,r,c,r-1,i);
        for(int i=0;i<r;i++)
            dfs(matrix,atl_vis,r,c,i,c-1);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pac_vis[i][j] && atl_vis[i][j]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};