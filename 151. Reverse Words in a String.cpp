vector<string> string_to_vector(string str){
    vector<string> ans;
    string temp="";
    for(int i=0;i<str.size();i++) {
        if (str[i] == ' ') {
            if (temp.size() == 0)
                continue;
            ans.push_back(temp);
            temp = "";
            continue;
        }
        temp+=str[i];
    }
    if(temp.size()!=0)
        ans.push_back(temp);
    return ans;
}

class Solution {
public:
    string reverseWords(string s) {
        vector<string> str=string_to_vector(s);
        int i=0,j=str.size()-1;
        while (i<=j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        string ans="";
        for(int i=0;i<str.size();i++)
            ans=ans+str[i]+" ";
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};