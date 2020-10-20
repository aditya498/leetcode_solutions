class RandomizedSet {
private:
    unordered_map<int,int> value_to_index;
    vector<int> rec;

    int generateRandom(){
        return rand()%rec.size();
    }

public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if(value_to_index.find(val)!=value_to_index.end())
            return false;
        value_to_index[val]=rec.size();
        rec.push_back(val);
        return true;
    }

    bool remove(int val) {
        if(value_to_index.find(val)==value_to_index.end())
            return false;
        int i=value_to_index[val];
        swap(rec[i],rec[rec.size()-1]);
        value_to_index[rec[i]]=i;
        rec.pop_back();
        value_to_index.erase(val);
        return true;
    }

    int getRandom() {
        return rec[generateRandom()];
    }
};

