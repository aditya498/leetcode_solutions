class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pos=1;
        int neg=1;
        int ans=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                pos=1;
                neg=1;
                ans=max(ans,0);
            } else if(nums[i]>0){
                pos=pos*nums[i];
                neg=neg*nums[i];
                ans=max(ans,pos);
            } else{
                if(neg<0){
                    pos=pos*nums[i];
                    neg=neg*nums[i];
                    swap(pos,neg);
                    ans=max(ans,pos);
                } else{
                    pos=pos*nums[i];
                    neg=neg*nums[i];
                    ans=max(ans,max(pos,neg));
                    neg=min(pos,neg);
                    pos=1;
                }
            }
        }
        return ans;
    }
};