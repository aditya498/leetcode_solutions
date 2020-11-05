class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long n=0;
        long n1=x;
        while (x!=0){
            n=n*10+x%10;
            x=x/10;
        }
        return n1==n;
    }
};