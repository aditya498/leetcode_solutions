vector<string> helper(string str,unordered_set<string> dict,unordered_map<string,vector<string>> &rec){
    vector<string> ans;
    if(str.size()==0)
        return ans;
    if(rec.find(str)!=rec.end())
        return rec[str];
    for(int i=0;i<str.size();i++){
        string word=str.substr(0,i+1);
        if(dict.find(word)==dict.end())
            continue;
        vector<string> temp=helper(str.substr(i+1),dict,rec);
        for(int j=0;j<temp.size();j++)
            ans.push_back(word+" "+temp[j]);
        if(i==str.size()-1)
            ans.push_back(word);
    }
    rec[str]=ans;
    return ans;
}

class Solution {
public:
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i=0;i<wordDict.size();i++)
            dict.insert(wordDict[i]);

        unordered_map<string,vector<string>> rec;
        return helper(str,dict,rec);
    }
};