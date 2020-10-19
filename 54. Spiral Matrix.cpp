class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0)
            return ans;
        int r=matrix.size();
        int c=matrix[0].size();
        int rs=0,re=r-1,cs=0,ce=c-1;
        bool r_rev=false,c_rev=false;
        bool row=true;
        while(true){
            if(rs>re || cs>ce)
                break;
            if(row){
                if(!r_rev) {
                    for (int i = cs; i <= ce; i++)
                        ans.push_back(matrix[rs][i]);
                    rs++;
                } else{
                    for(int i=ce;i>=cs;i--)
                        ans.push_back(matrix[re][i]);
                    re--;
                }
                r_rev=!r_rev;
                row=!row;
            } else{
                if(!c_rev) {
                    for (int i = rs; i <= re; i++)
                        ans.push_back(matrix[i][ce]);
                    ce--;
                } else{
                    for(int i=re;i>=rs;i--)
                        ans.push_back(matrix[i][cs]);
                    cs++;
                }
                c_rev=!c_rev;
                row=!row;
            }
        }
        return ans;
    }
};