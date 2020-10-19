class Pair{
public:
    int sum;
    unordered_map<int,int> sumRec;
};

Pair helper(TreeNode* root){
    if(root->left==NULL && root->right==NULL){
        Pair ans;
        ans.sum=root->val;
        ans.sumRec[root->val]=1;
        return ans;
    }

    Pair ans;
    ans.sum=root->val;
    if(root->left!=NULL) {
        Pair left = helper(root->left);
        ans.sum+=left.sum;
        unordered_map<int,int>::iterator it=left.sumRec.begin();
        while (it!=left.sumRec.end()){
            ans.sumRec[it->first]+=it->second;
            it++;
        }
    }
    if(root->right!=NULL) {
        Pair right = helper(root->right);
        ans.sum+=right.sum;
        unordered_map<int,int>::iterator it=right.sumRec.begin();
        while (it!=right.sumRec.end()){
            ans.sumRec[it->first]+=it->second;
            it++;
        }
    }
    ans.sumRec[ans.sum]+=1;
    return ans;
}

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;

        Pair rec=helper(root);

        vector<pair<int,int>> temp;
        unordered_map<int,int>::iterator it=rec.sumRec.begin();
        while (it!=rec.sumRec.end()){
            pair<int,int> p;
            p.first=it->first;
            p.second=it->second;
            temp.push_back(p);
            it++;
        }

        sort(temp.begin(),temp.end(),compare);
        int v=temp[0].second;
        for(int i=0;i<temp.size();i++){
            if(temp[i].second!=v)
                break;
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};