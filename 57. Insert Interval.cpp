class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        bool flag=true;
        for(int i=0;i<intervals.size();i++){
            if(newInterval[0]<intervals[i][0] && flag){
                flag=false;
                temp.push_back(newInterval);
            }
            temp.push_back(intervals[i]);
        }
        if(flag)
            temp.push_back(newInterval);
        vector<vector<int>> ans;
        int k=0;
        for(int i=0;i<temp.size();i++){
            if(k==0){
                ans.push_back(temp[i]);
                k++;
            }else{
                if(ans[k-1][1]>=temp[i][0])
                    ans[k-1][1]=max(temp[i][1],ans[k-1][1]);
                else{
                    ans.push_back(temp[i]);
                    k++;
                }
            }
        }
        return ans;
    }
};