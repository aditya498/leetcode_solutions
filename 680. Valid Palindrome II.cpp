class Solution {
public:
    bool validPalindrome(string str) {
        int i=0,j=str.size()-1;
        while (i<=j){
            if(str[i]!=str[j])
                break;
            i++;
            j--;
        }
        
        if(i>j)
            return true;
        
        int fi=i,fj=j;
        i++;
        while (i<=j){
            if(str[i]!=str[j])
                break;
            i++;
            j--;
        }

        if(i>j)
            return true;
        
        i=fi;
        j=fj;
        j--;
        
        while (i<=j){
            if(str[i]!=str[j])
                break;
            i++;
            j--;
        }

        if(i>j)
            return true;
        
        return false;
    }
};