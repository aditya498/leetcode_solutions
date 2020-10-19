void reverse(vector<int> &nums,int s,int e){
    int i=s,j=e;
    while (i<j)
        swap(nums[i++],nums[j--]);
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k<0)
            k=k+nums.size();
        k=k%nums.size();
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,0,nums.size()-1);
    }
};