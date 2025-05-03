class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap() {
        // set up a hashmap for mapping keys to set
        // the set maps timestamps to values
    }

    void set(string key, string value, int timestamp) {
        map[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) return "";
        vector<pair<int, string>>& vec = map[key];
        if (vec.empty() || timestamp < vec[0].first) return "";
        int l = 0;
        int r = vec.size() - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2; // need to use ceiling division
            // we choose floor or ceiling based on how we update pointers
            // since we want l = m, we should choose m to be the ceiling to ensure progress
            if (vec[m].first <= timestamp) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return vec[l].second;
    }
};
