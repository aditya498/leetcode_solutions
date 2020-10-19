class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> rec;
        rec.insert(1);
        while(n!=1){
            rec.insert(*rec.begin()*2);
            rec.insert(*rec.begin()*3);
            rec.insert(*rec.begin()*5);
            rec.erase(rec.begin());
            n--;
        }
        return *rec.begin();
    }
};