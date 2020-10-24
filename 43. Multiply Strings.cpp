string helper(string num1,char num2){
    string c="0";
    string ans="";
    for(int i=num1.size()-1;i>=0;i--){
        int s=((num1[i]-48)*(num2-48))+stoi(c);
        ans=to_string(s%10)+ans;
        c=to_string(s/10);
    }
    if(c!="0")
        ans=c+ans;
    return ans;
}

string add(string num1,string num2){
    string extra="";
    int d=abs(int(num1.size())-int(num2.size()));
    for(int i=0;i<d;i++)
        extra+="0";
    if(num1.size()<num2.size())
        num1=extra+num1;
    if(num2.size()<num1.size())
        num2=extra+num2;

    string c="0";
    string ans="";
    for(int i=num1.size()-1;i>=0;i--){
        int s=((num1[i]-48)+(num2[i]-48))+stoi(c);
        ans=to_string(s%10)+ans;
        c=to_string(s/10);
    }
    if(c!="0")
        ans=c+ans;
    return ans;
}

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans="";
        for(int i=num2.size()-1;i>=0;i--){
            string temp=helper(num1,num2[i]);
            if(ans=="")
                ans=temp;
            else {
                string extra="";
                for(int j=i;j<num2.size()-1;j++)
                    extra+="0";
                ans = add(ans, temp + extra);
            }
        }
        
        string final_res="";
        bool nonzero=false;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0')
                nonzero=true;
            if(nonzero)
                final_res=final_res+ans[i];
        }
        if(final_res.size()==0)
            final_res="0";
        
        return final_res;
    }
};