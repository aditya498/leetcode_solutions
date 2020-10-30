unordered_map<string,int> helper(string sen,int n){
    unordered_map<string,int> ans;
    int i=0;
    while (i<sen.size()){
        int j=i;
        string word="";
        while (j<i+n){
            word+=sen[j];
            j++;
        }
        ans[word]+=1;
        i=j;
    }
    return ans;
}

class Solution {
public:
    vector<int> findSubstring(string str, vector<string>& words) {
        unordered_map<string,int> pat;
        for(int i=0;i<words.size();i++)
            pat[words[i]]+=1;
        int len=words[0].size()*words.size();
        string sen="";
        vector<int> ans;
        for(int i=0;i<len;i++)
            sen+=str[i];
        if(helper(sen,words[0].size())==pat)
            ans.push_back(0);
        for(int i=len;i<str.size();i++){
            sen=sen.substr(1)+str[i];
            if(helper(sen,words[0].size())==pat)
                ans.push_back(i-len+1);
        }
        return ans; 
    }
};