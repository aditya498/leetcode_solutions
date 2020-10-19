class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0)
            return ans;
        vector<int> t;
        t.push_back(1);
        ans.push_back(t);
        int r=0;
        for(int i=2;i<=numRows;i++){
            vector<int> temp;
            int prev=0;
            for(int j=0;j<ans[r].size();j++){
                temp.push_back(prev+ans[r][j]);
                prev=ans[r][j];
            }
            temp.push_back(prev);
            ans.push_back(temp);
            r++;
        }
        return ans;
    }
};