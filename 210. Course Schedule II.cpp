bool dfs(vector<vector<int>> &graph,bool* processed,bool* processing,stack<int> &rec,int sv){
    processing[sv]=true;
    for(int i=0;i<graph[sv].size();i++){
        if(processed[graph[sv][i]])
            continue;
        if(processing[graph[sv][i]])
            return false;
        if(!dfs(graph,processed,processing,rec,graph[sv][i]))
            return false;
    }
    processed[sv]= true;
    processing[sv]=false;
    rec.push(sv);
    return true;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool* processed=new bool[numCourses]{0};
        bool* processing=new bool[numCourses]{0};
        bool possible=true;

        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

        stack<int> rec;
        for(int i=0;i<numCourses;i++){
            if(processed[i])
                continue;
            if(!dfs(graph,processed,processing,rec,i)){
                possible=false;
                break;
            }
        }

        if(!possible) {
            vector<int> ans;
            return ans;
        }

        vector<int> ans(numCourses);
        int i=numCourses-1;
        while (i>=0) {
            ans[i--] =rec.top();
            rec.pop();
        }

        return ans;
    }
};