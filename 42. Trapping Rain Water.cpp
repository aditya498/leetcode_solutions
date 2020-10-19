class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        int* left=new int[height.size()];
        int* right=new int[height.size()];
        left[0]=height[0];
        for(int i=1;i<height.size();i++)
            left[i]=max(left[i-1],height[i]);
        right[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--)
            right[i]=max(right[i+1],height[i]);
        
        int ans=0;
        for(int i=0;i<height.size();i++)
            ans=ans+min(left[i],right[i])-height[i];
        delete[] left;
        delete[] right;
        return ans;
    }
};