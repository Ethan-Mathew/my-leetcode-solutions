class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        std::unordered_set<int> seen;
        std::vector<int> repeats;

        for (int num : nums) {
            if (seen.find(num) != seen.end()) {
                repeats.push_back(num);
            } else {
                seen.insert(num);
            }
        }
        
        return repeats;
    }
};