class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            int l=0,r=matrix[i].size()-1;
            while (l<=r){
                matrix[i][l]=matrix[i][l]^1;
                if(l!=r)
                    matrix[i][r]=matrix[i][r]^1;
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }
        return matrix;
    }
};