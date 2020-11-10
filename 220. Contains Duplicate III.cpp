bool compare(pair<int,int> p1,pair<int,int> p2){
    if(p1.first!=p2.first)
        return p1.first<p2.first;
    return p1.second<p2.second;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>> rec(nums.size());
        for(int i=0;i<nums.size();i++){
            rec[i].first=nums[i];
            rec[i].second=i;
        }

        sort(rec.begin(),rec.end(),compare);

        for(int i=0;i<rec.size();i++){
            for(int j=i+1;j<rec.size();j++){
                if((long long)rec[i].first+t<rec[j].first)
                    break;
                else{
                    if(abs(rec[i].second-rec[j].second)<=k)
                        return true;
                }
            }
        }
        return false;
    }
};
