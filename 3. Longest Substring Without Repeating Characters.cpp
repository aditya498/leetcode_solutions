class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,ans=0;
        unordered_map<int,int> rec;
        while (j<s.size()){
            if(rec.find(s[j])==rec.end()){
                rec[s[j]]=j;
            } else if(rec[s[j]]<i)
                rec[s[j]]=j;
            else{
                i=rec[s[j]]+1;
                rec[s[j]]=j;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};