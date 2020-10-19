int helper(int n){
    int num=0;
    while (n!=0){
        num+=((n%10)*(n%10));
        n=n/10;
    }
    return num;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> rec;
        while (n!=1){
            if(rec.find(n)!=rec.end())
                return false;
            rec.insert(n);
            n=helper(n);
        }
        return true;
    }
};