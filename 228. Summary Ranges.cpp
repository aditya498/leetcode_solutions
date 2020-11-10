class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0,j=1;
        vector<string> ans;
        if(nums.size()==0)
            return ans;
        while (j<nums.size()){
            if(nums[j]-1==nums[j-1])
                j++;
            else{
                if(i!=j-1)
                    ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
                else
                    ans.push_back(to_string(nums[i]));
                i=j++;
            }
        }
        if(i!=j-1)
            ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
        else
            ans.push_back(to_string(nums[i]));
        return ans;        
    }
};