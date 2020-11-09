class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        int p=log2(num);
        if(p%2!=0)
            return false;
        return pow(4,p/2)==num;
    }
};