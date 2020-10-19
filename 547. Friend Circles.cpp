int getParent(int* parent,int v){
    while (v!=parent[v])
        v=parent[v];
    return v;
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& edges) {
        int n=edges.size();
        int* parent=new int[n];
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(edges[i][j]==0)
                    continue;
                int p1=getParent(parent,i);
                int p2=getParent(parent,j);
                parent[p1]=p2;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                ans++;
        }
        
        delete[] parent;
        
        return ans;
    }
};