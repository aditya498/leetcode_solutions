bool helper(vector<vector<char>>& board, string word,bool** visited,int r,int c,int i,int j){
    if(word.size()==0)
        return true;
    if(i<0 || j<0 || i>=r || j>=c || visited[i][j] || word[0]!=board[i][j])
        return false;
    visited[i][j]=true;
    bool ans=helper(board,word.substr(1),visited,r,c,i-1,j) || helper(board,word.substr(1),visited,r,c,i+1,j) || helper(board,word.substr(1),visited,r,c,i,j-1) || helper(board,word.substr(1),visited,r,c,i,j+1);
    visited[i][j]= false;
    return ans;
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        if(r==0)
            return true;
        int c=board[0].size();
        bool** visited=new bool*[r];
        for(int i=0;i<r;i++)
            visited[i]=new bool[c]{0};
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(helper(board,word,visited,r,c,i,j))
                    return true;
            }
        }
        return false;
    }
};