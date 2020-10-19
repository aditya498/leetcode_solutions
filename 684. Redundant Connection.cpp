int getParent(int* parent,int u){
    while (parent[u]!=u)
        u=parent[u];
    return u;
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int* parent=new int[edges.size()+1];
        for(int i=0;i<=edges.size();i++)
            parent[i]=i;
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            int pu=getParent(parent,edges[i][0]);
            int pv=getParent(parent,edges[i][1]);
            if(pu==pv)
                ans=edges[i];
            parent[pu]=pv;
        }
        return ans;
    }
};