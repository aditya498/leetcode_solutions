class Pair{
public:
    int v;
    int d;
};

class triplet{
public:
    int v;
    int w;
    int k;
};

class compare{
public:
    bool operator()(triplet t1,triplet t2){
        return t1.w>t2.w;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<Pair> *edges=new vector<Pair>[n];
        for(int i=0;i<flights.size();i++){
            Pair p;
            p.v=flights[i][1];
            p.d=flights[i][2];
            edges[flights[i][0]].push_back(p);
        }

        priority_queue<triplet,vector<triplet>,compare> pq;
        triplet temp;
        temp.v=src;
        temp.w=0;
        temp.k=k+1;
        pq.push(temp);

        while (pq.size()!=0){
            triplet cur=pq.top();
            pq.pop();
            if(cur.v==dst)
                return cur.w;
            if(cur.k==0)
                continue;
            for(int i=0;i<edges[cur.v].size();i++){
                temp.v=edges[cur.v][i].v;
                temp.w=cur.w+edges[cur.v][i].d;
                temp.k=cur.k-1;
                pq.push(temp);
            }
        }
        return -1;
    }
};