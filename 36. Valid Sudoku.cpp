bool checkRow(vector<vector<char>>& board,int n,int x){
    unordered_set<char> rec;
    for(int i=0;i<n;i++){
        if(board[x][i]=='.')
            continue;
        if(rec.find(board[x][i])!=rec.end())
            return false;
        rec.insert(board[x][i]);
    }
    return true;
}

bool checkCol(vector<vector<char>>& board,int n,int y){
    unordered_set<char> rec;
    for(int i=0;i<n;i++){
        if(board[i][y]=='.')
            continue;
        if(rec.find(board[i][y])!=rec.end())
            return false;
        rec.insert(board[i][y]);
    }
    return true;
}

bool checkBox(vector<vector<char>>& board,int x,int y) {
    unordered_set<char> rec;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(board[i][j]=='.')
                continue;
            if(rec.find(board[i][j])!=rec.end())
                return false;
            rec.insert(board[i][j]);
        }
    }
    return true;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            if(!checkRow(board,board[0].size(),i))
                return false;
        }
        
        for(int i=0;i<board[0].size();i++){
            if(!checkCol(board,board.size(),i))
                return false;
        }
        
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                if(!checkBox(board,i,j))
                    return false;
            }
        }
        return true;
    }
};