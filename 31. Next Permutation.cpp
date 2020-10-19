int nextLargestIndex(vector<int> &nums,int pos,int n){
    for(int i=n-1;i>pos;i--){
        if(nums[i]>nums[pos])
            return i;
    }
    return -1;
}

void reverse(vector<int> &nums,int pos,int n){
    int i=pos+1;
    int j=n-1;
    while (i<j)
        swap(nums[i++],nums[j--]);
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pos=i;
                break;
            }
        }
        
        if(pos!=-1){
            int i=nextLargestIndex(nums,pos,nums.size());
            swap(nums[pos],nums[i]);
        }
        reverse(nums,pos,nums.size());
    }
};