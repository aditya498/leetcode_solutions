class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        unordered_set<int> rec;
        for(int i=0;i<arr.size();i++){
            if(rec.find(arr[i])==rec.end())
                rec.insert(arr[i]);
            else
                return arr[i];
        }
        return -1;
    }
};