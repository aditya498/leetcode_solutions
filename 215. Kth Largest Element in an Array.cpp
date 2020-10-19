int partition(vector<int>& nums,int s,int e){
    int pivot=nums[s];
    int pos=s;
    for(int i=s+1;i<=e;i++){
        if(nums[i]<=pivot)
            pos++;
    }

    swap(nums[s],nums[pos]);
    int i=s,j=e;
    while(i<pos && j>pos){
        if(nums[i]<=pivot && nums[j]>pivot){
            i++;
            j--;
        } else if(nums[i]>pivot && nums[j]<=pivot){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        else if(nums[i]<=pivot)
            i++;
        else
            j--;
    }

    return pos;
}

void helper(vector<int> &nums,int k,int s,int e){
    if(s>=e)
        return;
    int pivot=partition(nums,s,e);
    if(pivot==k)
        return;
    else if(pivot<k)
        helper(nums,k,pivot+1,e);
    else
        helper(nums,k,s,pivot-1);
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        helper(nums,nums.size()-k,0,nums.size()-1);
        return nums[nums.size()-k];
    }
};