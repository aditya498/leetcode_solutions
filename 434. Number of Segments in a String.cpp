class Solution {
public:
    int countSegments(string str) {
        int ans=0;
        for(int i=1;i<str.size();i++){
            if(str[i-1]!=' ' && str[i]==' ')
                ans++;
        }
        if(str.size()!=0 && str[str.size()-1]!=' ')
            ans++;
        return ans;
    }
};