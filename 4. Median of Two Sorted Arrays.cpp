double helper(vector<int> &x,vector<int> &y){
    int s=0,e=x.size();
    double ans=0;
    while(s<=e){
        int m=(s+e)/2;
        int partition_x=m;
        int partition_y=(x.size()+y.size()+1)/2-partition_x;

        int maxLeft_x = (partition_x == 0) ? INT_MIN : x[partition_x - 1];
        int minRight_x = (partition_x == x.size()) ? INT_MAX : x[partition_x];

        int maxLeft_y = (partition_y == 0) ? INT_MIN : y[partition_y - 1];
        int minRight_y = (partition_y == y.size()) ? INT_MAX : y[partition_y];


        if(maxLeft_x<=minRight_y && maxLeft_y<=minRight_x){
            if((x.size()+y.size())%2==0)
                ans=(max(maxLeft_x,maxLeft_y)+min(minRight_x,minRight_y))/2.0;
            else
                ans= max(maxLeft_x,maxLeft_y);
            break;
        } else if(maxLeft_x>minRight_y)
            e=m-1;
        else
            s=m+1;
    }
    return ans;
}

double findMid(vector<int>& nums){
    if(nums.size()%2!=0)
        return nums[nums.size()/2];
    else
        return (nums[nums.size()/2-1]+nums[nums.size()/2])/2.0;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0){
            return findMid(nums2);
        } else if(nums2.size()==0){
            return findMid(nums1);
        } else if(nums1.size()<=nums2.size())
            return helper(nums1,nums2);
        else
            return helper(nums2,nums1);
    }
};