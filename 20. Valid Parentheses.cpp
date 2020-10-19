int isOpening(char sign){
    string bracket="[{(";
    for(int i=0;i<3;i++){
        if(sign==bracket[i])
            return i;
    }
    return -1;
}

int isClosing(char sign){
    string bracket="]})";
    for(int i=0;i<3;i++){
        if(sign==bracket[i])
            return i;
    }
    return -1;
}

class Solution {
public:
    bool isValid(string bracket) {
        string opening="[{(";
        string closing="]})";
        stack<char> rec;
        for(int i=0;i<bracket.size();i++){
            if(isOpening(bracket[i])!=-1)
                rec.push(bracket[i]);
            else{
                if(rec.size()==0)
                    return false;
                else if(opening[isClosing(bracket[i])]==rec.top())
                    rec.pop();
                else
                    return false;
            }
        }
        return rec.size()==0;
    }
};