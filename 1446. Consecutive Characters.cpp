class Solution {
public:
    int maxPower(string str) {
        int ans=0;
        int temp=0;
        for(int i=0;i<str.size();i++){
            if(i!=str.size()-1 && str[i]==str[i+1])
                temp++;
            else{
                temp++;
                ans=max(temp,ans);
                temp=0;
            }
        }
        return ans;
    }
};