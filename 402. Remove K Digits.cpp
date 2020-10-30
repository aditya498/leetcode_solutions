class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> rec;
        int i=0;
        while (i<num.size()){
            if(rec.size()==0 || k==0) {
                if(num[i]==48 && rec.size()==0){
                    i++;
                    continue;
                }
                rec.push(num[i]);
                i++;
            }else{
                if(rec.top()>num[i]){
                    k--;
                    rec.pop();
                } else {
                    rec.push(num[i]);
                    i++;
                }
            }
        }

        string temp="";
        while (rec.size()!=0){
            temp=rec.top()+temp;
            rec.pop();
        }

        if(k!=0){
            if(k>temp.size())
                temp="";
            else
                temp=temp.substr(0,temp.size()-k);
        }
        
        if(temp.size()==0)
            temp="0";

        return temp;
    }
};