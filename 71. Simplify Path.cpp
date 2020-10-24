vector<string> str_to_vec(string str){
    vector<string> ans;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='/'){
            if(temp.size()==0)
                continue;
            ans.push_back(temp);
            temp="";
            continue;
        }
        temp+=str[i];
    }
    if(temp.size()!=0)
        ans.push_back(temp);
    return ans;
}

class Solution {
public:
    string simplifyPath(string str) {
        vector<string> path=str_to_vec(str);
        
        stack<string> rec;
        for(int i=0;i<path.size();i++){
            if(path[i]==".")
                continue;
            else if(path[i]==".."){
                if(rec.size()!=0)
                    rec.pop();
            } else
                rec.push(path[i]);
        }
        
        string ans="";
        while (rec.size()!=0) {
            ans = "/" + rec.top() + ans;
            rec.pop();
        }
        if(ans.size()==0)
            ans="/";
        
        return ans;
    }
};