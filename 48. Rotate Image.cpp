class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int k=0;k<matrix.size();k++){
            for(int i=k;i<matrix.size();i++)
                swap(matrix[k][i],matrix[i][k]);
        }
        for(int i=0;i<matrix.size();i++){
            int x=0,y=matrix.size()-1;
            while (x<y){
                swap(matrix[i][x],matrix[i][y]);
                x++;
                y--;
            }
        }
    }
};