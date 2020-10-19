int removalRequired(string str){
    stack<char> rec;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(')
            rec.push(str[i]);
        else if(str[i]==')'){
            if(rec.size()==0 || rec.top()==')')
                rec.push(str[i]);
            else
                rec.pop();
        }
    }
    return rec.size();
}

void helper(string str,int req,unordered_set<string> &rec,unordered_set<string> &dp){
    if(dp.find(str)!=dp.end())
        return;
    if(req==0){
        int r=removalRequired(str);
        if(r==0)
            rec.insert(str);
        return;
    }

    for(int i=0;i<str.size();i++){
        if(!(str[i]=='(' || str[i]==')'))
            continue;
        string temp="";
        if(i==0)
            temp=str.substr(1);
        else
            temp=str.substr(0,i)+str.substr(i+1);
        helper(temp,req-1,rec,dp);
        dp.insert(temp);
    }
}

class Solution {
public:
    vector<string> removeInvalidParentheses(string str) {
        int req=removalRequired(str);

        unordered_set<string> rec;
        unordered_set<string> dp;
        helper(str,req,rec,dp);
        vector<string> ans;
        unordered_set<string>::iterator it=rec.begin();
        while (it!=rec.end()){
            ans.push_back(*it);
            it++;
        }

        return ans;
    }
};

