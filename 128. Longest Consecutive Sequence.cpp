class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> rec;
        
        for(int i=0;i<nums.size();i++)
            rec[nums[i]]=true;
        
        for(int i=0;i<nums.size();i++){
            if(rec.find(nums[i]-1)!=rec.end())
                rec[nums[i]]=false;
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(rec[nums[i]]==false)
                continue;
            int n=nums[i];
            int c=0;
            while(rec.find(n)!=rec.end()){
                c++;
                n++;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};