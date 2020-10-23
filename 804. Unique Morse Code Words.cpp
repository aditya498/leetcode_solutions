class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string map[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> rec;
        for(int i=0;i<words.size();i++){
            string temp="";
            for(int j=0;j<words[i].size();j++)
                temp+=map[words[i][j]-97];
            rec.insert(temp);
        }
        return rec.size();
    }
};