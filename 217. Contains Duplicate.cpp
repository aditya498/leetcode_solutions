class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> rec;
        for(int i=0;i<nums.size();i++){
            if(rec.find(nums[i])==rec.end())
                rec.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};