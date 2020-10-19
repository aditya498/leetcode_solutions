pair<int,int> findMax(pair<int,int> p1,pair<int,int> p2){
    int l1=p1.second-p1.first+1;
    int l2=p2.second-p2.first+1;
    if(l1>=l2)
        return p1;
    else
        return p2;
}

class Solution {
public:
    string longestPalindrome(string str) {
        int n=str.size();
        pair<int,int> ans;
        ans.first=0;
        ans.second=0;
        for(int i=0;i<n;i++){
            int l=i-1,r=i+1;
            pair<int,int> len;
            len.first=i;
            len.second=i;
            while (l>=0 && r<n && str[l]==str[r]){
                len.first=l--;
                len.second=r++;
            }
            ans=findMax(ans,len);
        }

        for(int i=0;i<n-1;i++){
            if(str[i]!=str[i+1])
                continue;
            int l=i-1;
            int r=i+2;
            pair<int,int> len;
            len.first=i;
            len.second=i+1;
            while (l>=0 && r<n && str[l]==str[r]){
                len.first=l--;
                len.second=r++;
            }
            ans=findMax(ans,len);
        }

        return str.substr(ans.first,ans.second-ans.first+1);
    }
};