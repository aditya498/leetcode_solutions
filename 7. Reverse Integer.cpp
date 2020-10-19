class Solution {
public:
    int reverse(int x) {
        bool positive=x>=0;
        if(x==INT_MIN)
            return 0;
        x=abs(x);
        long long num=0;
        while (x!=0){
            num=num*10+x%10;
            if(num>INT_MAX)
                return 0;
            x=x/10;
        }
        if(!positive)
            num=(-1)*num;
        return num;
    }
};