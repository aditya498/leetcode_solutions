class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& input) {
        map<vector<int>,vector<string>> ans;
        for(int i=0;i<input.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<input[i].size();j++)
                temp[input[i][j]-97]++;
            ans[temp].push_back(input[i]);
        }
        
        vector<vector<string>> result;
        map<vector<int>,vector<string>>::iterator it=ans.begin();
        while (it!=ans.end()){
            result.push_back(it->second);
            it++;
        }
        
        return result;
    }
};