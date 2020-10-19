bool helper(int* status,vector<vector<int>> &edges,int v){
    if(status[v]==1)
        return false;

    status[v]=1;
    for(int i=0;i<edges[v].size();i++){
        if(status[edges[v].at(i)]!=2){
            bool ans=helper(status,edges,edges[v].at(i));
            if(!ans)
                return ans;
        }
    }
    status[v]=2;
    return true;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        for(int i=0;i<prerequisites.size();i++)
            edges.at(prerequisites[i][1]).push_back(prerequisites[i][0]);
        int* status=new int[numCourses]{0};
        for(int i=0;i<numCourses;i++) {
            if(status[i]==0) {
                bool ans = helper(status, edges, i);
                if (!ans)
                    return false;
            }
        }
        delete[] status;
        return true;
    }
};