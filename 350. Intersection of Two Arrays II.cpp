class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> rec;
        vector<int> ans;

        for(int i=0;i<nums1.size();i++)
            rec[nums1[i]]+=1;
        for(int i=0;i<nums2.size();i++){
            if(rec.find(nums2[i])!=rec.end())
                if(rec[nums2[i]]>0){
                    ans.push_back(nums2[i]);
                    rec[nums2[i]]--;
                }
        }
        return ans;
    }
};