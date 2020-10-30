class Solution {
public:
    string reverseStr(string str, int k) {
        bool rev=true;
        int i=0;
        while (i<str.size()){
            if(rev){
                int s=i,e=min(i+k-1,int(str.size())-1);
                while (s<=e){
                    swap(str[s],str[e]);
                    s++;
                    e--;
                }
            }
            i=i+k;
            rev=!rev;
        }
        return str;
    }
};