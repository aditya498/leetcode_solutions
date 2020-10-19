class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int prev=0;
        for(int i=0;i<nums.size();i++){
            prev+=nums[i];
            ans.push_back(prev);
        }
        return ans;
    }
};