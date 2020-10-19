class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> rec;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int s=rec.top();
                rec.pop();
                int f=rec.top();
                rec.pop();
                rec.push(f+s);
            } else if(tokens[i]=="-"){
                int s=rec.top();
                rec.pop();
                int f=rec.top();
                rec.pop();
                rec.push(f-s);
            } else if(tokens[i]=="*"){
                int s=rec.top();
                rec.pop();
                int f=rec.top();
                rec.pop();
                rec.push(f*s);
            } else if(tokens[i]=="/"){
                int s=rec.top();
                rec.pop();
                int f=rec.top();
                rec.pop();
                rec.push(f/s);
            } else
                rec.push(stoi(tokens[i]));
        }
        return rec.top();
    }
};