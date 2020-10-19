class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> rec;
        int* left=new int[n];
        int* right=new int[n];
        
        for(int i=0;i<n;i++){
            while (rec.size()!=0 && heights[rec.top()]>=heights[i])
                rec.pop();
            if(rec.size()==0)
                left[i]=-1;
            else
                left[i]=rec.top();
            rec.push(i);
        }
        
        while(rec.size()!=0)
            rec.pop();
        
        for(int i=n-1;i>=0;i--){
            while (rec.size()!=0 && heights[rec.top()]>=heights[i])
                rec.pop();
            if(rec.size()==0)
                right[i]=n;
            else
                right[i]=rec.top();
            rec.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,heights[i]*(right[i]-left[i]-1));
        
        return ans;
    }
};