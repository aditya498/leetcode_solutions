class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int nl=0,nr=0;
        int i=0;
        while (i<s.size()){
            if(s[i]=='L')
                nl++;
            else if(s[i]=='R')
                nr++;
            if(nl==nr && nl!=0){
                ans++;
                nl=0;
                nr=0;
            }
            i++;
        }
        return ans;
    }
};