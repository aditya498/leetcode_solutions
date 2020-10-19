class Solution {
public:
    string addBinary(string a, string b) {
        string extra="";
        int d=abs(int(a.size())-int(b.size()));
        for(int i=0;i<d;i++)
            extra+="0";
        if(a.size()>b.size())
            b=extra+b;
        if(b.size()>a.size())
            a=extra+a;

        char carry='0';
        int count=0;
        string result="";
        for(int i=a.size()-1;i>=0;i--){
            count=(a[i]!=48)+(b[i]!=48)+(carry!=48);
            if(count==0) {
                result = "0" + result;
                carry='0';
            } else if(count==1){
                result="1"+result;
                carry='0';
            } else if(count==2){
                result="0"+result;
                carry='1';
            } else{
                result="1"+result;
                carry='1';
            }
        }
        if(carry!=48)
            result="1"+result;
        return result;
    }
};