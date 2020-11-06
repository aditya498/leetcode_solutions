class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> rec(501,0);
        for(int i=0;i<nums.size();i++)
            rec[nums[i]]++;
        int sum=0;
        for(int i=0;i<=500;i++){
            int temp=rec[i];
            rec[i]=sum;
            sum+=temp;
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            ans.push_back(rec[nums[i]]);
        return ans;
    }
};