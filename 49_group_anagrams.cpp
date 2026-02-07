class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagramMap;
        for (const string& str : strs) {
            string encoderString = "00000000000000000000000000";
            for (char c : str) {
                encoderString[static_cast<int>(c) - static_cast<int>('a')]++;
            }
            anagramMap[encoderString].push_back(std::move(str));
        }

        vector<vector<string>> solution;
        for (auto& anagrams : anagramMap) {
            solution.push_back(std::move(anagrams.second));
        }

        return solution;
    }
};