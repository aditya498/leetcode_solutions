bool isSatisfying(int rec[256],int freq[256]){
    for(int i=0;i<256;i++){
        if(freq[i]==0)
            continue;
        if(freq[i]>rec[i])
            return false;
    }
    return true;
}

class Solution {
public:
    string minWindow(string str, string pat) {
        int rec[256]={0};
        int freq[256]={0};
        for(int i=0;i<pat.size();i++)
            freq[pat[i]]++;

        int i=0,j=0;
        int fi=0,fj=str.size()+2;
        rec[str[0]]++;
        while (j<str.size()){
            if(isSatisfying(rec,freq)){
                if(fj-fi>j-i){
                    fj=j;
                    fi=i;
                }
                rec[str[i]]--;
                i++;
            } else{
                j++;
                rec[str[j]]++;
            }
        }
        
        string ans="";
        if(fj==str.size()+2)
            return ans;
        for(int k=fi;k<=fj;k++)
            ans+=str[k];
        
        return ans;
    }
};