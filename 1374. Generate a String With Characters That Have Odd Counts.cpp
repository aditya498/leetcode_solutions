class Solution {
public:
    string generateTheString(int n) {
        string ans="";
        for(int i=0;i<n;i++)
            ans+="a";
        if(n%2!=0)
            return ans;
        else
            return ans.substr(0,n-1)+"b";
    }
};