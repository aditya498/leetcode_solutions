class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int  ran[26]={0};
        int mag[26]={0};
        
        for(int i=0;i<ransomNote.size();i++)
            ran[ransomNote[i]-97]+=1;
        for(int i=0;i<magazine.size();i++)
            mag[magazine[i]-97]+=1;
        
        for(int i=0;i<26;i++){
            if(ran[i]>mag[i])
                return false;
        }
        return true;
    }
};