class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        double f=log10(n)/log10(3);
        return f==floor(f);
    }
};