class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string sen1="",sen2="";
        for(int i=0;i<word1.size();i++)
            sen1+=word1[i];
        for(int i=0;i<word2.size();i++)
            sen2+=word2[i];
        return sen1==sen2;
    }
};
