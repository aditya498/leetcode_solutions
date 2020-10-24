vector<int> helper(string str){
    vector<int> ans;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='.'){
            ans.push_back(stoi(temp));
            temp="";
            continue;
        }
        temp+=str[i];
    }
    if(temp.size()!=0)
        ans.push_back(stoi(temp));
    return ans;
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1=helper(version1);
        vector<int> ver2=helper(version2);

        int d=abs(int(ver1.size())-int(ver2.size()));
        if(ver1.size()<ver2.size()){
            for(int i=0;i<d;i++)
                ver1.push_back(0);
        }
        if(ver2.size()<ver1.size()){
            for(int i=0;i<d;i++)
                ver2.push_back(0);
        }
        
        for(int i=0;i<ver1.size();i++){
            if(ver1[i]>ver2[i])
                return 1;
            if(ver1[i]<ver2[i])
                return -1;
        }
        return 0;
    }
};