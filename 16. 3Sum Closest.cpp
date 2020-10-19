class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int ans;
        bool first= true;

        for(int i=0;i<nums.size();i++){
            int target=t-nums[i];
            int j=i+1,k=nums.size()-1;
            while (j<k){
                int s=nums[j]+nums[k];
                if(s<target)
                    j++;
                else if(s>target)
                    k--;
                else
                    return t;
                if(first){
                    ans=s+nums[i];
                    first= false;
                } else{
                    int da=abs(ans-t);
                    int dt=abs(s+nums[i]-t);
                    if(dt<da)
                        ans=s+nums[i];
                }
            }
        }
        return ans;
    }
};