class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> rec;
        unordered_set<int> ans;
        
        for(int i=0;i<nums1.size();i++)
            rec.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(rec.find(nums2[i])!=rec.end())
                ans.insert(nums2[i]);
        }
        
        vector<int> result;
        unordered_set<int>::iterator it=ans.begin();
        while (it!=ans.end()){
            result.push_back(*it);
            it++;
        }
        return result;
    }
};