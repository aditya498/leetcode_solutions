void dfs(vector<vector<char>>& grid,bool** &visited,int r,int c,int i,int j){
    if(i<0 || j<0 || i>=r || j>=c || visited[i][j] || grid[i][j]=='0')
        return;
    visited[i][j]=true;
    dfs(grid,visited,r,c,i+1,j);
    dfs(grid,visited,r,c,i-1,j);
    dfs(grid,visited,r,c,i,j+1);
    dfs(grid,visited,r,c,i,j-1);
}


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        bool** visited=new bool*[grid.size()];
        for(int i=0;i<grid.size();i++)
            visited[i]=new bool[grid[i].size()]{0};

        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(grid,visited,grid.size(),grid[i].size(),i,j);
                }
            }
        }

        return ans;
    }
};