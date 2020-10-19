class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> rec;
        for(int i=0;i<nums.size();i++){
            if(rec.find(nums[i])==rec.end())
                rec[nums[i]]=i;
            else{
                if(i-rec[nums[i]]<=k)
                    return true;
                rec[nums[i]]=i;
            }
        }
        return false;
    }
};