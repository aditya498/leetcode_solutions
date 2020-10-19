class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,string> rec;
        rec['2']="abc";
        rec['3']="def";
        rec['4']="ghi";
        rec['5']="jkl";
        rec['6']="mno";
        rec['7']="pqrs";
        rec['8']="tuv";
        rec['9']="wxyz";

        for(int i=digits.size()-1;i>=0;i--){
            if(ans.size()==0){
                for(int j=0;j<rec[digits[i]].size();j++){
                    string temp="";
                    temp+=rec[digits[i]][j];
                    ans.push_back(temp);
                }
            } else{
                int l=rec[digits[i]].size()-1;
                int l1=ans.size();
                for(int j=0;j<l;j++){
                    for(int k=0;k<l1;k++)
                        ans.push_back(ans[k]);
                }
                for(int j=0;j<(l+1);j++){
                    for(int k=l1*j;k<l1*(j+1);k++)
                        ans[k]=rec[digits[i]][j]+ans[k];
                }
            }
        }
        
        return ans;
    }
};