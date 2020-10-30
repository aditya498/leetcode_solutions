class StockSpanner {
    stack<pair<int,int>> rec;
    int i;
public:
    StockSpanner() {
        i=1;
    }

    int next(int price) {
        pair<int,int> p;
        p.first=price;
        p.second=i;
        
        while (rec.size()!=0 && rec.top().first<=price)
            rec.pop();
        int ans=0;
        if(rec.size()==0)
            ans=i;
        else
            ans=i-rec.top().second;
        rec.push(p);
        i++;
        return ans;
    }
};