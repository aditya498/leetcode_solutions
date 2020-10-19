pair<string,string> helper(char n1,char n2,string carry){
    string num1="";
    string num2="";
    num1+=n1;
    num2+=n2;
    
    int x=stoi(num1);
    int y=stoi(num2);
    int c=stoi(carry);
    
    int sum=x+y+c;
    pair<string,string> ans;
    ans.first=to_string(sum%10);
    ans.second=to_string(sum/10);
    return ans;
}

class Solution {
public:
    string addStrings(string num1, string num2) {
        int dif=abs(int(num1.size())-int(num2.size()));
        string extra="";
        for(int i=0;i<dif;i++)
            extra+="0";
        if(num1.size()<num2.size())
            num1=extra+num1;
        else
            num2=extra+num2;

        string carry="0";
        string result="";
        for(int i=num1.size()-1;i>=0;i--){
            pair<string ,string > temp=helper(num1[i],num2[i],carry);
            result=temp.first+result;
            carry=temp.second;
        }
        if(carry!="0")
            result=carry+result;
        return result;
    }
};