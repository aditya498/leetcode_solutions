Node* helper(Node* node,unordered_map<int,Node*> &rec) {
    if(node==NULL)
        return NULL;
    Node* temp=new Node(node->val);
    rec[temp->val]=temp;

    for(int i=0;i<node->neighbors.size();i++) {
        if(rec.find(node->neighbors.at(i)->val)==rec.end()) 
            temp->neighbors.push_back(helper(node->neighbors.at(i), rec));
        else
            temp->neighbors.push_back(rec[node->neighbors.at(i)->val]);
    }
    return temp;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> rec;
        return helper(node,rec);
    }
};