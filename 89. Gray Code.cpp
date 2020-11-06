vector<string> helper(int n){
    vector<string> ans;
    if(n==0){
        ans.push_back("0");
        return ans;
    }
    if(n==1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    
    vector<string> temp=helper(n-1);
    for(int i=0;i<temp.size();i++)
        ans.push_back("0"+temp[i]);
    for(int i=temp.size()-1;i>=0;i--)
        ans.push_back("1"+temp[i]);
    
    return ans;
}

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> temp=helper(n);
        vector<int> ans;
        for(int i=0;i<temp.size();i++){
            int val=0;
            int fac=1;
            for(int j=temp[i].size()-1;j>=0;j--) {
                val += ((temp[i][j] - 48) * fac);
                fac*=2;
            }
            ans.push_back(val);
        }
        return ans;
    }
};