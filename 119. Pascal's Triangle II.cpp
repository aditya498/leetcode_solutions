class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int arr[2][rowIndex+1];
        for(int i=0;i<2;i++){
            for(int j=0;j<=rowIndex;j++)
                arr[i][j]=0;
        }
        bool flag=1;
        for(int i=0;i<=rowIndex;i++){
            int prev=0;
            if(i==0)
                prev=1;
            for(int j=0;j<=i;j++){
                arr[flag][j]=arr[flag^1][j]+prev;
                prev=arr[flag^1][j];
            }
            flag=flag^1;
        }

        vector<int> ans;
        for(int i=0;i<=rowIndex;i++){
            if(arr[flag^1][i]==0)
                continue;
            ans.push_back(arr[flag ^ 1][i]);
        }
        
        return ans;
    }
};