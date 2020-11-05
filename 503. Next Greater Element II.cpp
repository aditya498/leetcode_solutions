class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        stack<int> rec;
        vector<int> ans(n);
        
        for(int i=2*n-1;i>=n;i--){
            while (rec.size()!=0 && nums[i]>=rec.top())
                rec.pop();
            rec.push(nums[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            while (rec.size()!=0 && nums[i]>=rec.top())
                rec.pop();
            if(rec.size()==0)
                ans[i]=-1;
            else
                ans[i]=rec.top();
            rec.push(nums[i]);
        }
        
        return ans;
    }
};