class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string digits[10]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string tens[10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string extra[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string den[3]={"Thousand","Million","Billion"};

        int count=0;
        vector<string> ans;
        string temp="";
        int place=0;
        int prev=0;
        while (num!=0){
            int d=num%10;
            num=num/10;
            count++;

            if(d!=0 && count%3==0){
                if(temp.size()!=0)
                    temp=digits[d]+" "+"Hundred"+" "+temp;
                else
                    temp=digits[d]+" "+"Hundred";
            } else if(d!=0 && count%3==2){
                if(d!=1){
                    if(temp.size()!=0)
                        temp=tens[d]+" "+temp;
                    else
                        temp=tens[d];
                }
                else
                    temp=extra[prev];
            } else if(d!=0){
                temp=digits[d];
            }

            if(count%3==0){
                if(num!=0) {
                    if(temp.size()==0)
                        ans.push_back(den[place]);
                    else{
                        ans.push_back(temp);
                        ans.push_back(den[place]);
                    }
                }
                else if(temp.size()!=0)
                    ans.push_back(temp);
                place++;
                temp="";
            } else if(num==0){
                ans.push_back(temp);
            }
            prev=d;
        }

        string res="";
        bool flag=false;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=="Thousand" || ans[i]=="Million" || ans[i]=="Billion"){
                if(flag)
                    continue;
                flag=true;
            } else
                flag=false;
            res=res+ans[i]+" ";
        }
        res=res.substr(0,res.size()-1);
        return res;
    }
};
