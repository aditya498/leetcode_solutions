class Pair{
public:
    int val;
    int freq;
};

class compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.freq>p2.freq;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> rec;
        for(int i=0;i<nums.size();i++)
            rec[nums[i]]++;

        priority_queue<Pair,vector<Pair>,compare> pq;
        unordered_map<int,int>::iterator it=rec.begin();
        int i=0;
        Pair temp;
        while (i<k){
            temp.val=it->first;
            temp.freq=it->second;
            pq.push(temp);
            i++;
            it++;
        }
        
        while (it!=rec.end()){
            if(pq.top().freq<it->second){
                pq.pop();
                temp.val=it->first;
                temp.freq=it->second;
                pq.push(temp);
            }
            it++;
        }
        
        vector<int> ans;
        while (pq.size()!=0){
            ans.push_back(pq.top().val);
            pq.pop();
        }
        
        return ans;
    }
};