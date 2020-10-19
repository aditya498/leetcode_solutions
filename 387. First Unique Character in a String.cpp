class Solution {
public:
    int firstUniqChar(string str) {
        int  rec[26]={0};

        for(int i=0;i<str.size();i++)
            rec[str[i]-97]+=1;
        
        for(int i=0;i<str.size();i++){
            if(rec[str[i]-97]==1)
                return i;
        }
        return -1;
    }
};