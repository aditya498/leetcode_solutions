class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int s=0,e=matrix.size()*matrix[0].size()-1;
        while (s<=e){
            int m=(s+e)/2;
            int r=m/matrix[0].size();
            int c=m%matrix[0].size();
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                s=m+1;
            else
                e=m-1;
        }
        return false;
    }
};