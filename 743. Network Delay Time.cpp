class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        int* weight=new int[n+1];
        for(int i=0;i<=n;i++)
            weight[i]=INT_MAX;
        weight[k]=0;
        for(int j=0;j<n-1;j++){
            for(int i=0;i<edges.size();i++){
                if(weight[edges[i][0]]==INT_MAX)
                    continue;
                if(weight[edges[i][0]]+edges[i][2]<weight[edges[i][1]])
                    weight[edges[i][1]]=weight[edges[i][0]]+edges[i][2];
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(weight[i]==INT_MAX)
                return -1;
            ans=max(ans,weight[i]);
        }
        return ans;
    }
};