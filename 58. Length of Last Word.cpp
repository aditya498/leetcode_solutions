class Solution {
public:
    int lengthOfLastWord(string str) {
        int l=0;
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]!=' '){
                l=i+1;
                break;
            }
        }
        str=str.substr(0,l);
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(str[i]==' ')
                ans = 0;
            else
                ans++;
        }
        return ans;
    }
};