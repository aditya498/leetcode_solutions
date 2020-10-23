class TrieNode{
public:
    char val;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char val){
        this->val=val;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
    }
};


class WordDictionary {
private:
    TrieNode* root;

    void addWord(TrieNode* root,string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        int i=word[0]-97;
        if(root->children[i]==NULL)
            root->children[i]=new TrieNode(word[0]);
        addWord(root->children[i],word.substr(1));
    }

    bool search(TrieNode* root,string word){
        if(word.size()==0)
            return root->isTerminal;
        if(word[0]!='.'){
            int i=word[0]-97;
            if(root->children[i]==NULL)
                return false;
            return search(root->children[i],word.substr(1));
        }
        
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL && search(root->children[i],word.substr(1)))
                return true;
        }
        return false;
    }

public:
    WordDictionary() {
        root=new TrieNode('\0');
    }

    void addWord(string word) {
        addWord(root,word);
    }

    bool search(string word) {
        return search(root,word);
    }
};