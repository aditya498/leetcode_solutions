class Solution {
public:
    int jump(vector<int>& nums) {
        int pos=0,des=0,count=0;
        for(int i=0;i<nums.size()-1;i++){
            des=max(des,i+nums[i]);
            if(i==pos){
                pos=des;
                count++;
            }
        }
        return count;
    }
};
