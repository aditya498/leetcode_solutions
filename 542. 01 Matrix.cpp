class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.size(),vector<int>(matrix[0].size(),-1));
        queue<pair<int,int>> pending;

        int r=matrix.size();
        int c=matrix[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    ans[i][j]=0;
                    pair<int,int> p;
                    p.first=i;
                    p.second=j;
                    pending.push(p);
                }
            }
        }

        int pos[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

        while (pending.size()!=0){
            pair<int,int> temp=pending.front();
            pending.pop();
            for(int k=0;k<4;k++){
                pair<int,int> p;
                p.first=temp.first+pos[k][0];
                p.second=temp.second+pos[k][1];
                if(p.first<0 || p.second<0 || p.first>=r || p.second>=c || ans[p.first][p.second]!=-1)
                    continue;
                ans[p.first][p.second]=ans[temp.first][temp.second]+1;
                pending.push(p);
            }
        }

        return ans;
    }
};