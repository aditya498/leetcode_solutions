class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> rec;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(rec.find(target-nums[i])!=rec.end()){
                ans.push_back(rec[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            rec[nums[i]]=i;
        }
        return ans;
    }
};