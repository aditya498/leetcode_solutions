class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int* freq1=new int[26]{0};
        int* freq2=new int[26]{0};
        for(int i=0;i<s.size();i++){
            freq1[s[i]-97]++;
            freq2[t[i]-97]++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])
                return false;
        }
        return true;
    }
};