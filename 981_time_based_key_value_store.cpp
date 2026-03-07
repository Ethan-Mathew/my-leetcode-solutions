class TimeMap {
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back(std::pair<int, std::string>{timestamp, value});
    }
    
    string get(string key, int timestamp) {
        std::vector<std::pair<int, std::string>>& keySearchRange = timeMap[key];
        
        int left = 0;
        int right = keySearchRange.size() - 1;

        int last_valid = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (keySearchRange[mid].first <= timestamp) {
                last_valid = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (last_valid == -1) {
            return "";
        }

        return keySearchRange[last_valid].second;
    }
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> timeMap;
};