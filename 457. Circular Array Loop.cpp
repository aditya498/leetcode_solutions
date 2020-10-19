int getNext(vector<int>& nums,int i,int direction){
    int n=nums.size();
    if(direction && nums[i]<0)
        return -1;
    if(!direction && nums[i]>0)
        return -1;
    int next=i+nums[i];
    while(next<0)
        next+=n;
    next=next%n;
    
    if(i==next)
        return -1;
    else
        return next;
}

bool isCircular(vector<int>& nums,int i){
    if(nums[i]==0)
        return false;
    bool direction=nums[i]>0;
    int slow=i;
    int fast=getNext(nums,slow,direction);

    if(slow==fast)
        return false;

    while(true){
        if(slow==-1 || fast==-1)
            return false;
        if(slow==fast)
            break;
        slow=getNext(nums,slow,direction);
        fast=getNext(nums,fast,direction);
        if(slow==-1 || fast==-1)
            return false;
        fast=getNext(nums,fast,direction);

    }
    return true;
}

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(isCircular(nums,i))
                return true;
        }
        return false;
    }
};