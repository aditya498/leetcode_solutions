class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candies=INT_MIN;
        for(int i=0;i<candies.size();i++)
            max_candies=max(max_candies,candies[i]);
        vector<bool> ans;
        for(int i=0;i<candies.size();i++)
            ans.push_back((candies[i]+extraCandies)>=max_candies);
        return ans;
    }
};