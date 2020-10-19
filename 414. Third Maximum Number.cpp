class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> rec;
        for(int i=0;i<nums.size();i++)
            rec.insert(nums[i]);

        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_set<int>::iterator it=rec.begin();
        int i=0;
        int temp=INT_MIN;
        while (i<3 && it!=rec.end()){
            pq.push(*it);
            temp=max(temp,*it);
            it++;
            i++;
        }
        if(it==rec.end() && i!=3)
            return temp;
        while (it!=rec.end()){
            if(pq.top()<*it){
                pq.pop();
                pq.push(*it);
            }
            it++;
        }
        return pq.top();
    }
};