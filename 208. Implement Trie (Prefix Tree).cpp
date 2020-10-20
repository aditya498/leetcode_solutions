class TrieNode{
public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
    }
};


class Trie {
private:
    TrieNode* root;

    void insert(TrieNode* root,string word) {
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        int i=word[0]-97;
        if(root->children[i]==NULL)
            root->children[i]=new TrieNode(word[0]);
        insert(root->children[i],word.substr(1));
    }

    bool search(TrieNode* root,string word) {
        if(word.size()==0)
            return root->isTerminal;
        int i=word[0]-97;
        if(root->children[i]==NULL)
            return false;
        return search(root->children[i],word.substr(1));
    }

    bool startsWith(TrieNode* root,string prefix) {
        if(prefix.size()==0)
            return true;
        int i=prefix[0]-97;
        if(root->children[i]==NULL)
            return false;
        return startsWith(root->children[i],prefix.substr(1));
    }

public:
    Trie() {
        root=new TrieNode('\0');
    }

    void insert(string word) {
        insert(root,word);
    }

    bool search(string word) {
        return search(root,word);
    }

    bool startsWith(string prefix) {
        return startsWith(root,prefix);
    }
};
