class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int l=INT_MAX;
        for(int i=0;i<strs.size();i++)
            l=min(l,int(strs[i].size()));
        
        string ans="";
        for(int i=0;i<l;i++){
            char c=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=c)
                    return ans;
            }
            ans+=c;
        }
        return ans;
    }
};