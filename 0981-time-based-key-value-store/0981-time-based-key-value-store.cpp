class TimeMap {
public:

    // key -> list of {timestamp, value}
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {

        // Insert in sorted order (timestamps are increasing)
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        // Key doesn't exist
        if (mp.find(key) == mp.end())
            return "";

        auto &arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;

        string ans = "";

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {
                // Valid timestamp, try to find a larger one
                ans = arr[mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */