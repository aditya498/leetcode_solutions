int getPriority(string s){
    if(s=="+" || s=="-")
        return 1;
    if(s=="*" || s=="/")
        return 2;
    return -1;
}

vector<string> getPostfix(vector<string> str){
    stack<string> rec;
    vector<string> exp;
    for(int i=0;i<str.size();i++){
        if(getPriority(str[i])==-1)
            exp.push_back(str[i]);
        else{
            while (rec.size()!=0 && getPriority(str[i])<=getPriority(rec.top())){
                exp.push_back(rec.top());
                rec.pop();
            }
            rec.push(str[i]);
        }
    }
    while (rec.size()!=0){
        exp.push_back(rec.top());
        rec.pop();
    }
    return exp;
}

int evalPostfix(vector<string> exp){
    stack<int> rec;
    for(int i=0;i<exp.size();i++){
        if(getPriority(exp[i])==-1)
            rec.push(stoi(exp[i]));
        else{
            int s=rec.top();
            rec.pop();
            int f=rec.top();
            rec.pop();

            if(exp[i]=="+")
                rec.push(f+s);
            else if(exp[i]=="-")
                rec.push(f-s);
            else if(exp[i]=="*")
                rec.push(f*s);
            else
                rec.push(f/s);
        }
    }
    return rec.top();
}

class Solution {
public:
    int calculate(string s) {
        string exp="";
        bool noOp=true;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')
                exp+=s[i];
            string t="";
            t+=s[i];
            if(s[i]!=' ' && getPriority(t)!=-1)
                noOp=false;
        }
        if(noOp)
            return stoi(exp);

        vector<string> ex;
        string temp="";
        for(int i=0;i<exp.size();i++){
            string t="";
            t+=exp[i];
            if(getPriority(t)!=-1){
                ex.push_back(temp);
                temp="";
                temp+=exp[i];
                ex.push_back(temp);
                temp="";
                continue;
            }
            temp+=exp[i];
        }
        ex.push_back(temp);
        vector<string> postfix=getPostfix(ex);
        return evalPostfix(postfix);
    }
};