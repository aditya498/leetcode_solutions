vector<string> string_to_vector(string str){
    vector<string> ans;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            ans.push_back(temp);
            temp="";
            continue;
        }
        temp+=str[i];
    }
    ans.push_back(temp);
    return ans;
}

void reverse(string &str){
    int i=0,j=str.size()-1;
    while (i<=j) {
        swap(str[i],str[j]);
        i++;
        j--;
    }
}

class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp=string_to_vector(s);
        for(int i=0;i<temp.size();i++)
            reverse(temp[i]);
        string ans="";
        for(int i=0;i<temp.size();i++)
            ans=ans+temp[i]+" ";
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};