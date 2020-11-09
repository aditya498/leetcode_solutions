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
    if(temp!="")
        ans.push_back(temp);
    return ans;
}

class Solution {
public:
    bool wordPattern(string pat, string s) {
        unordered_map<char,string> rec;
        vector<string> str=string_to_vector(s);
        if(str.size()!=pat.size())
            return false;
        unordered_set<string> visited;
        for(int i=0;i<pat.size();i++){
            if(rec.find(pat[i])==rec.end()) {
                if(visited.find(str[i])==visited.end()) {
                    rec[pat[i]] = str[i];
                    visited.insert(str[i]);
                } else
                    return false;
            }
            else if(rec[pat[i]]!=str[i])
                return false;
        }
        return true;
    }
};