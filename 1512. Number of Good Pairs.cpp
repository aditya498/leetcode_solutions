class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> rec;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+rec[nums[i]];
            rec[nums[i]]+=1;
        }
        return ans;
    }
};