class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int* count=new int[n+1]{0};
        for(int i=0;i<trust.size();i++){
            count[trust[i][0]]--;
            count[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(count[i]==n-1)
                return i;
        }
        return -1;
    }
};