class Pair{
public:
    string str;
    int d;
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> rec;
        for(int i=0;i<deadends.size();i++)
            rec.insert(deadends[i]);

        unordered_set<string> visited;
        visited.insert("0000");

        queue<Pair> pending;
        Pair p;
        p.str="0000";
        p.d=0;
        pending.push(p);

        while (pending.size()!=0){
            Pair temp=pending.front();
            pending.pop();
            if(temp.str==target)
                return temp.d;
            if(rec.find(temp.str)!=rec.end())
                continue;
            for(int i=0;i<4;i++){
                string left=temp.str.substr(0,i);
                string right=temp.str.substr(i+1);
                int d=temp.str[i]-48;
                string pat1=left+to_string((d+1+10)%10)+right;
                string pat2=left+to_string((d-1+10)%10)+right;
                if(visited.find(pat1)==visited.end()){
                    p.str=pat1;
                    p.d=temp.d+1;
                    pending.push(p);
                    visited.insert(pat1);
                }
                if(visited.find(pat2)==visited.end()){
                    p.str=pat2;
                    p.d=temp.d+1;
                    pending.push(p);
                    visited.insert(pat2);
                }
            }
        }
        return -1;
    }
};