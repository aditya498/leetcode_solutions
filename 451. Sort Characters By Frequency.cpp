class Pair{
public:
    char c;
    int num;
};

class compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.num<p2.num;
    }
};

class Solution {
public:
    string frequencySort(string str) {
        vector<int> freq(256,0);
        for(int i=0;i<str.size();i++)
            freq[str[i]]++;
        
        priority_queue<Pair,vector<Pair>,compare> pq;
        Pair temp;
        for(int i=0;i<256;i++){
            if(freq[i]==0)
                continue;
            temp.c=i;
            temp.num=freq[i];
            pq.push(temp);
        }
        
        string ans="";
        while (pq.size()!=0){
            for(int i=0;i<pq.top().num;i++)
                ans+=pq.top().c;
            pq.pop();
        }
        
        return ans;
    }
};