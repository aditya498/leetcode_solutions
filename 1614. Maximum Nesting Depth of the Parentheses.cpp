class Solution {
public:
    int maxDepth(string str) {
        stack<char> rec;
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(')
                rec.push('(');
            else if(str[i]==')')
                rec.pop();
            ans=max(ans,int(rec.size()));
        }
        return ans;
    }
};