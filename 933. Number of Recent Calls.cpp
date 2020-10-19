class RecentCounter {
    queue<int> rem;
public:
    RecentCounter() {
    }

    int ping(int t) {
        rem.push(t);
        int rmin=t-3000;
        while(rem.size()!=0 && rem.front()<rmin)
            rem.pop();
        return rem.size();
    }
};