class Solution {
public:
    bool checkValidString(string str) {
        stack<int> open;
        stack<int> star;
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='(')
                open.push(i);
            else if(str[i]=='*')
                star.push(i);
            else{
                if(open.size()!=0)
                    open.pop();
                else if(star.size()!=0)
                    star.pop();
                else
                    return false;
            }
        }
        
        while (open.size()!=0 && star.size()!=0){
            if(open.top()>star.top())
                break;
            open.pop();
            star.pop();
        }
        
        return open.size()==0;
    }
};