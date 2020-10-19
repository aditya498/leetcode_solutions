bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return true;
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        return true;
    return false;
}

class Solution {
public:
    string reverseVowels(string str) {
        int i=0,j=str.size()-1;

        while(i<=j){
            if(isVowel(str[i]) && isVowel(str[j])){
                swap(str[i],str[j]);
                i++;
                j--;
            } else if(!isVowel(str[i]))
                i++;
            else if(!isVowel(str[j]))
                j--;
        }

        return str;
    }
};