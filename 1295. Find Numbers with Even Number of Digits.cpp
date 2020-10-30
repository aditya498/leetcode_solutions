int helper(int num){
    int d=0;
    while (num!=0){
        d++;
        num=num/10;
    }
    return d;
}

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(helper(nums[i])%2==0)
                ans++;
        }
        return ans;
    }
};