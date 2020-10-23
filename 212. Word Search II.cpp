class TrieNode{
public:
    char val;
    TrieNode** children;
    bool isTerminal;
    string word;

    TrieNode(char c){
        val=c;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
        word="";
    }
};

class Trie{
private:
    TrieNode* root;
    void insert(TrieNode* root,string word,string temp){
        if(word.size()==0){
            root->isTerminal=true;
            root->word=temp;
            return;
        }

        int i=word[0]-97;
        if(root->children[i]==NULL)
            root->children[i]=new TrieNode(word[0]);
        insert(root->children[i],word.substr(1),temp);
    }

    void helper(vector<vector<char>> &board,bool** visited,TrieNode* root,unordered_set<string> &rec,int i,int j){
        if(root->isTerminal){
            rec.insert(root->word);
        }
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j])
            return;
        if(root->children[board[i][j]-97]==NULL)
            return;
        
        visited[i][j]=true;
        
        helper(board,visited,root->children[board[i][j]-97],rec,i+1,j);
        helper(board,visited,root->children[board[i][j]-97],rec,i-1,j);
        helper(board,visited,root->children[board[i][j]-97],rec,i,j+1);
        helper(board,visited,root->children[board[i][j]-97],rec,i,j-1);
        
        visited[i][j]=false;
    }


public:
    Trie(){
        root=new TrieNode('\0');
    }

    void insert(string word){
        insert(root,word,word);
    }

    vector<string> findWords(vector<vector<char>> &board){
        unordered_set<string> rec;
        vector<string> ans;

        if(board.size()==0)
            return ans;
        
        bool** visited=new bool*[board.size()];
        for(int i=0;i<board.size();i++)
            visited[i]=new bool[board[0].size()]{0};
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++)
                helper(board,visited,root,rec,i,j);
        }
        
        for(int i=0;i<board.size();i++)
            delete[] visited[i];
        delete[] visited;
        
        unordered_set<string>::iterator  it=rec.begin();
        while (it!=rec.end()){
            ans.push_back(*it);
            it++;
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(int i=0;i<words.size();i++)
            trie.insert(words[i]);
        
        return trie.findWords(board);
    }
};