class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k_size;
public:
    KthLargest(int k, vector<int>& nums) {
        k_size=k;
        k=min(int(nums.size()),k);
        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        for(int i=k;i<nums.size();i++){
            if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if(pq.size()<k_size)
            pq.push(val);
        else if(pq.top()<val){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
