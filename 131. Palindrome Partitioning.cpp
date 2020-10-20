bool isPalindrome(string str){
    int l=0,r=str.size()-1;
    while (l<=r){
        if(str[l]!=str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void helper(string str,vector<string> temp,vector<vector<string>> &ans){
    if(str.size()==0){
        ans.push_back(temp);
        return;
    }
    
    for(int i=0;i<str.size();i++){
        if(isPalindrome(str.substr(0,i+1))){
            temp.push_back(str.substr(0,i+1));
            helper(str.substr(i+1),temp,ans);
            temp.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> partition(string str) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(str,temp,ans);
        return ans;
    }
};