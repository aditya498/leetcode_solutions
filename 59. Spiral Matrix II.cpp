class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        if(n==0)
            return matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i].push_back(0);
            }
        }
        int r=n;
        int c=n;
        int rs=0,re=r-1,cs=0,ce=c-1;
        bool r_rev=false,c_rev=false;
        bool row=true;
        int num=1;
        while(true){
            if(rs>re || cs>ce)
                break;
            if(row){
                if(!r_rev) {
                    for (int i = cs; i <= ce; i++)
                        matrix[rs][i]=num++;
                    rs++;
                } else{
                    for(int i=ce;i>=cs;i--)
                        matrix[re][i]=num++;
                    re--;
                }
                r_rev=!r_rev;
                row=!row;
            } else{
                if(!c_rev) {
                    for (int i = rs; i <= re; i++)
                        matrix[i][ce]=num++;
                    ce--;
                } else{
                    for(int i=re;i>=rs;i--)
                        matrix[i][cs]=num++;
                    cs++;
                }
                c_rev=!c_rev;
                row=!row;
            }
        }
        return matrix;
    }
};