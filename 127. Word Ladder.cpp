bool edgePossible(string word1,string word2){
    int changes=0;
    for(int i=0;i<word1.size();i++){
        if(word1[i]!=word2[i]){
            changes++;
            if(changes>1)
                return false;
        }
    }
    return true;
}

class Pair{
public:
    int v;
    int d;
};

int bfs(vector<vector<int>> &edges,int n,int s,int e){
    Pair p;
    p.v=s;
    p.d=1;
    queue<Pair> pending;
    pending.push(p);
    vector<bool> visited(n,false);
    visited[s]=true;
    while (pending.size()!=0){
        Pair temp=pending.front();
        pending.pop();
        if(temp.v==e)
            return temp.d;
        for(int i=0;i<edges[temp.v].size();i++){
            if(!visited[edges[temp.v][i]]){
                p.v=edges[temp.v][i];
                p.d=temp.d+1;
                pending.push(p);
                visited[p.v]=true;
            }
        }
    }
    return 0;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int s=0,e=-1;
        vector<vector<int>> edges(wordList.size()+1);
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord)
                e=i+1;
            for(int j=i+1;j<wordList.size();j++){
                if(edgePossible(wordList[i],wordList[j])){
                    edges[i+1].push_back(j+1);
                    edges[j+1].push_back(i+1);
                }
            }
        }
        
        for(int i=0;i<wordList.size();i++){
            if(edgePossible(beginWord,wordList[i])){
                edges[0].push_back(i+1);
                edges[i+1].push_back(0);
            }
        }
        if(e==-1)
            return 0;
        return bfs(edges,wordList.size()+1,s,e);
    }
};