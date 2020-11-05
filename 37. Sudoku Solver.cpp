bool checkRow(vector<vector<char>> &board,int r,char k){
    for(int i=0;i<9;i++){
        if(board[r][i]==k)
            return false;
    }
    return true;
}

bool checkCol(vector<vector<char>> &board,int c,char k){
    for(int i=0;i<9;i++){
        if(board[i][c]==k)
            return false;
    }
    return true;
}

bool checkBox(vector<vector<char>> &board,int r,int c,char k){
    r=r-r%3;
    c=c-c%3;
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(board[i][j]==k)
                return false;
        }
    }
    return true;
}

bool helper(vector<vector<char>> &board,int i,int j){
    if(i==8 && j==9)
        return true;
    if(j==9){
        j=0;
        i++;
    }
    
    if(board[i][j]!='.')
        return helper(board,i,j+1);
    
    for(int k=1;k<=9;k++){
        if(checkRow(board,i,k+48) && checkCol(board,j,k+48) && checkBox(board,i,j,k+48)){
            board[i][j]=k+48;
            bool ans=helper(board,i,j+1);
            if(ans)
                return ans;
            board[i][j]='.';
        }
    }
    return false;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
};