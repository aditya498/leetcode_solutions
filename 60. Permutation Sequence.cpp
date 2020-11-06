void helper(vector<int> factorial,vector<int> digits,int n,int k,string &ans){
    if(n==0)
        return;
    int d=(k/factorial[n-1])-(k%factorial[n-1]==0?1:0);
    ans=ans+to_string(digits[d]);
    vector<int> new_digits;
    for(int i=0;i<digits.size();i++){
        if(i==d)
            continue;
        new_digits.push_back(digits[i]);
    }
    k=k-d*factorial[n-1];
    n--;
    helper(factorial,new_digits,n,k,ans);
}

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        vector<int> digits;
        vector<int> factorial;
        factorial.push_back(1);
        for(int i=1;i<=9;i++)
            factorial.push_back(factorial[i-1]*i);
        for(int i=1;i<=n;i++)
            digits.push_back(i);
        helper(factorial,digits,n,k,ans);
        return ans;
    }
};