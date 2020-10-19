class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        bool rz=false;
        bool cz=false;
        
        for(int i=0;i<matrix[0].size();i++)
            rz=rz||(matrix[0][i]==0);
        for(int i=0;i<matrix.size();i++)
            cz=cz||(matrix[i][0]==0);
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        if(rz){
            for(int i=0;i<matrix[0].size();i++)
                matrix[0][i]=0;
        }
        if(cz){
            for(int i=0;i<matrix.size();i++)
                matrix[i][0]=0;
        }
    }
};