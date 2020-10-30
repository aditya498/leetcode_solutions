int helper(int num){
    int sum=0;
    while (num!=0){
        sum+=num%10;
        num=num/10;
    }
    return sum;
}

class Solution {
public:
    int addDigits(int num) {
        while (true){
            int s=helper(num);
            if(num==s){
                num=s;
                break;
            }
            num=s;
        }      
        return num;
    }
};