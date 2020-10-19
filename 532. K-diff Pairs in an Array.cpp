class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,bool> rec;

        int ans=0;

        if(k==0){
            for(int i=0;i<nums.size();i++) {
                if(rec.find(nums[i])!=rec.end()) {
                    if(rec[nums[i]])
                        ans += 1;
                    rec[nums[i]]=false;
                } else {
                    rec[nums[i]] = true;
                }
            }
            return ans;
        }

        for(int i=0;i<nums.size();i++)
            rec[nums[i]] = true;

        ans=0;
        for(int i=0;i<nums.size();i++){
            if(!rec[nums[i]])
                continue;
            if(rec.find(nums[i]-k)!=rec.end() && rec[nums[i]-k])
                ans+=1;
            if(rec.find(nums[i]+k)!=rec.end() && rec[nums[i]+k])
                ans+=1;
            rec[nums[i]]=false;
        }

        return ans;
    }
};