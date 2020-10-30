class Solution {
public:
    string decodeString(string str) {
        stack<char> rec;
        for(int i=0;i<str.size();i++){
            if(str[i]!=']')
                rec.push(str[i]);
            else{
                string temp="";
                while (rec.top()!='['){
                    temp=rec.top()+temp;
                    rec.pop();
                }
                rec.pop();

                string s="";
                while (rec.size()!=0 && rec.top()>=48 && rec.top()<=57){
                    s=rec.top()+s;
                    rec.pop();
                }
                
                int n=stoi(s);
                string final_str="";
                for(int i=0;i<n;i++)
                    final_str+=temp;
                
                for(int i=0;i<final_str.size();i++)
                    rec.push(final_str[i]);
            }
        }
        
        string ans="";
        while (rec.size()!=0){
            ans=rec.top()+ans;
            rec.pop();
        }
        
        return ans;
    }
};