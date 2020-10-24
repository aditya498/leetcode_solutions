class Solution {
public:
    string removeDuplicateLetters(string str) {
        stack<char> rec;
        vector<bool> visited(26,false);
        vector<int> lastIndex(26,-1);

        for(int i=0;i<str.size();i++)
            lastIndex[str[i]-97]=i;

        for(int i=0;i<str.size();i++){
            if(visited[str[i]-97])
                continue;
            while (rec.size()!=0){
                if(rec.top()<str[i] || lastIndex[rec.top()-97]<i)
                    break;
                visited[rec.top()-97]=false;
                rec.pop();
            }
            rec.push(str[i]);
            visited[str[i]-97]=true;
        }
        
        string ans="";
        while (rec.size()!=0){
            ans=rec.top()+ans;
            rec.pop();
        }
        
        return ans;
    }
};