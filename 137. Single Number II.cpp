class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask=1;
        vector<int> ans(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++)
                ans[i]+=((nums[j] & mask)==0?0:1);
            ans[i]=ans[i]%3;
            if(i!=31)
                mask=mask<<1;
        }

        int val=0;
        long fac=1;
        for(int i=0;i<32;i++){
            val+=(fac*ans[i]);
            fac*=2;
        }

        return val;
    }
};