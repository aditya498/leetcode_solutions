class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        int i=0;
        while (i<=n-4){
            while (i>0 && nums[i]==nums[i-1])
                i++;
            if(i>n-4)
                break;
            int j=i+1;
            while (j<=n-3){
                while (j>(i+1) && j<n && nums[j]==nums[j-1])
                    j++;
                if(j>n-3)
                    break;
                int sum=nums[i]+nums[j];
                int k=j+1;
                int l=n-1;
                while (k<l){
                    if(sum+nums[k]+nums[l]<target)
                        k++;
                    else if(sum+nums[k]+nums[l]>target)
                        l--;
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        ans.push_back(temp);
                        k++;
                        l--;
                    while (k<l && nums[k]==nums[k-1])
                        k++;
                    while (k<l && l<n-1 && nums[l]==nums[l+1])
                        l--;
                    }
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};