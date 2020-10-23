vector<string> string_to_vector(string str){
    vector<string> ans;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            ans.push_back(temp);
            temp="";
            continue;
        }
        temp+=str[i];
    }
    ans.push_back(temp);
    return ans;
}


class TrieNode{
public:
    char val;
    TrieNode** children;
    bool isTerminal;
    int index;
    string word;
    
    TrieNode(char val){
        this->val=val;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
            children[i]=NULL;
        isTerminal=false;
        index=-1;
        word="";
    }
};

class Trie{
private:
    TrieNode *root;

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

    string helper(TrieNode* root,string word,string temp){
        if(word.size()==0){
            if(root->isTerminal)
                return root->word;
            return temp;
        }
        if(root->isTerminal)
            return root->word;
        int i=word[0]-97;
        if(root->children[i]==NULL)
            return temp;
        return helper(root->children[i],word.substr(1),temp);
    }
    
public:
    Trie(){
        root=new TrieNode('\0');
    }

    void insert(string word){
        insert(root,word,word);
    }

    string helper(string word){
        return helper(root,word,word);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(int i=0;i<dictionary.size();i++)
            trie.insert(dictionary[i]);

        vector<string> temp=string_to_vector(sentence);
        string ans="";
        for(int i=0;i<temp.size();i++){
            ans=ans+trie.helper(temp[i])+" ";
        }
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};