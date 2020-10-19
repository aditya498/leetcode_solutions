void dfs(vector<vector<char>>& board,bool** &visited,int r,int c,int i,int j){
    if(i<0 || i>=r || j<0 || j>=c || visited[i][j] || board[i][j]!='O')
        return;
    board[i][j]='1';
    visited[i][j]=true;
    dfs(board,visited,r,c,i+1,j);
    dfs(board,visited,r,c,i-1,j);
    dfs(board,visited,r,c,i,j+1);
    dfs(board,visited,r,c,i,j-1);
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        
        bool** visited=new bool*[board.size()];
        for(int i=0;i<board.size();i++)
            visited[i]=new bool[board[0].size()]{0};
        
        for(int i=0;i<board.size();i++){
            int c1=0,c2=board[0].size()-1;
            if(board[i][c1]=='O')
                dfs(board,visited,board.size(),board[0].size(),i,c1);
            if(board[i][c2]=='O')
                dfs(board,visited,board.size(),board[0].size(),i,c2);
        }

        for(int i=0;i<board[0].size();i++){
            int r1=0,r2=board.size()-1;
            if(board[r1][i]=='O')
                dfs(board,visited,board.size(),board[0].size(),r1,i);
            if(board[r2][i]=='O')
                dfs(board,visited,board.size(),board[0].size(),r2,i);
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='1')
                    board[i][j]='O';
            }
        }
        
        for(int i=0;i<board.size();i++)
            delete[] visited[i];
        delete[] visited;
    }
};