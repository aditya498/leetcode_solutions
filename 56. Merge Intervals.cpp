class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        ans.push_back(intervals[0]);
        while (i<intervals.size()){
            if(ans[ans.size()-1][1]>=intervals[i][0]) 
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};