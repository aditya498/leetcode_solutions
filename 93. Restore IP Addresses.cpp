void helper(string str,int n,string temp,vector<string> &ans){
    if(n==0 && str.size()==0){
        temp=temp.substr(0,temp.size()-1);
        ans.push_back(temp);
        return;
    }
    if(n<=0 || str.size()==0)
        return;
    
    string port="";
    for(int i=0;i<min(3,int(str.size()));i++){
        if(i==1 && str[i-1]=='0')
            return;
        port=port+str[i];
        if(stoi(port)>255)
            return;
        helper(str.substr(i+1),n-1,temp+port+".",ans);
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string str) {
        string temp="";
        vector<string> ans;
        helper(str,4,temp,ans);
        return ans;
    }
};