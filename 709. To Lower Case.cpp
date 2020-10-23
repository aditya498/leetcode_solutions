class Solution {
public:
    string toLowerCase(string str) {
        string result="";
        for(int i=0;i<str.size();i++){
            if(str[i]>=65 && str[i]<=90)
                result+=(str[i]+32);
            else
                result+=str[i];
        }
        return result;
    }
};