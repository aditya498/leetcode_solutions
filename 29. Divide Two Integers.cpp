class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;

        double d=dividend/divisor;
        int ans=floor(d);

        return ans;
    }
};