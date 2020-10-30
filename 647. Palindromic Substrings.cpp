class Solution {
public:
    int countSubstrings(string str) {
        int ans=0;
        
        for(int i=0;i<str.size();i++){
            ans++;
            int l=i-1,r=i+1;
            while (l>=0 && r<str.size()){
                if(str[l]!=str[r])
                    break;
                ans++;
                l--;
                r++;
            }
        }
        
        for(int i=0;i<str.size();i++){
            int l=i-1,r=i;
            while (l>=0 && r<str.size()){
                if(str[l]!=str[r])
                    break;
                ans++;
                l--;
                r++;
            }
        }
        
        return ans;
    }
};