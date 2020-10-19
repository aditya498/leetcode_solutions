int largestRectangleHostpgram(vector<int>& heights) {
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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> temp(c);

        for(int i=0;i<c;i++)
            temp[i]=0;

        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='0')
                    temp[j]=0;
                else
                    temp[j]++;
            }
            ans=max(ans,largestRectangleHostpgram(temp));
        }

        return ans;
    }
};