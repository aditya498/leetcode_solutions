class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==0)
            return 0;
        int i=0,j=0;
        int count=1;
        while (i<chars.size()-1){
            if(chars[i]==chars[i+1]) {
                count++;
                i++;
            }else{
                string c=to_string(count);
                chars[j]=chars[i];
                j++;
                i++;
                if(count==1)
                    continue;
                for(int k=0;k<c.size();k++)
                    chars[j+k]=c[k];
                count=1;
                j=j+c.size();
            }
        }
        string c=to_string(count);
        chars[j]=chars[i];
        j++;
        i++;
        if(count==1)
            return j;
        for(int k=0;k<c.size();k++)
            chars[j+k]=c[k];
        count=1;
        j=j+c.size();
        return j;
    }
};