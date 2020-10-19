int getParent(int* parent,int u){
    while (parent[u]!=u)
        u=parent[u];
    return u;
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ans1;
        vector<int> ans2;

        unordered_map<int,int> rec;
        for(int i=0;i<edges.size();i++){
            if(rec.find(edges[i][1])==rec.end())
                rec[edges[i][1]]=edges[i][0];
            else{
                ans2=edges[i];
                vector<int> temp;
                temp.push_back(rec[edges[i][1]]);
                temp.push_back(edges[i][1]);
                ans1=temp;
                break;
            }
        }

        int* parent=new int[edges.size()+1];
        for(int i=0;i<=edges.size();i++)
            parent[i]=i;
        
        if(ans1.size()!=0) {
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == ans2.at(0) && edges[i][1] == ans2.at(1))
                    continue;
                int pu = getParent(parent, edges[i][0]);
                int pv = getParent(parent, edges[i][1]);
                if (pu == pv)
                    return ans1;
                parent[pu] = pv;
            }
            return ans2;
        }

        vector<int> ans;
        for (int i = 0; i < edges.size(); i++) {
            int pu = getParent(parent, edges[i][0]);
            int pv = getParent(parent, edges[i][1]);
            if (pu == pv)
                ans=edges[i];
            parent[pu] = pv;
        }

        return ans;
    }
};