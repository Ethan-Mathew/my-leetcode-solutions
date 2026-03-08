class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        std::unordered_map<std::string, std::vector<std::string>> groupedStrings;

        for (std::string& s : strings) {
            std::string encoder = "";
            for (int i{1}; i < s.length(); i++) {
                int charDiff = s[i] - s[i - 1];
                if (charDiff < 0) {
                    charDiff += 26;
                }
                encoder += ' ';
                encoder += std::to_string(charDiff);
            }

            std::cout << encoder << "\n";

            groupedStrings[encoder].push_back(s);
        }

        std::vector<std::vector<std::string>> solutions;
        for (auto pairing : groupedStrings) {
            solutions.push_back(pairing.second);
        }

        return solutions;
    }
};
