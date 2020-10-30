class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i=0;
        if(s.size()!=t.size())
            return false;
        
        unordered_map<char,char> mapping;
        unordered_set<char> visited;
        
        while (i<s.size()){
            if(mapping.find(s[i])==mapping.end()){
                if(visited.find(t[i])!=visited.end())
                    return false;
                mapping[s[i]]=t[i];
                visited.insert(t[i]);
            } else{
                if(mapping[s[i]]!=t[i])
                    return false;
            }
            i++;
        }
        return true;
    }
};