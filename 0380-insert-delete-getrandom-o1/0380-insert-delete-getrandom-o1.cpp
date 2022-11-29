class RandomizedSet {
    vector<int> items;
    unordered_map<int, int> umap;
public:
    RandomizedSet() {
        
    }
    bool insert(int val) {
        if (umap.count(val)) {
            return false;
        }
        items.emplace_back(val);
        umap[val] = items.size() - 1;
        return true;
    }
    bool remove(int val) {
        if (!umap.count(val)) {
            return false;
        }
        int currIdx = umap[val];
        int lastVal = items[items.size()-1];
        swap(items[currIdx], items[items.size()-1]);
        umap[lastVal] = currIdx;
        items.pop_back();
        umap.erase(val);
        return true;
    }
    int getRandom() {
        return items[rand() % items.size()];
    }
};