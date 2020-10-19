class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if(maxHeap.size()==0){
            maxHeap.push(num);
            return;
        }

        if(maxHeap.top()>num)
            maxHeap.push(num);
        else
            minHeap.push(num);
        if(abs(int(maxHeap.size())-int(minHeap.size()))<=1)
            return;
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else{
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.size()==0)
            return 0;
        double ans;
        if(maxHeap.size()==minHeap.size())
            ans=(maxHeap.top()+minHeap.top())/2.0;
        else if(maxHeap.size()>minHeap.size())
            ans=maxHeap.top();
        else
            ans=minHeap.top();
        return ans;
    }
};