class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMin = arrays[0][0];
        int globalMax = arrays[0][arrays[0].size() - 1];
        int greatestDist = std::numeric_limits<int>::min();

        for (int i{1}; i < arrays.size(); i++) {
            int localMin = arrays[i][0];
            int localMax = arrays[i][arrays[i].size() - 1];

            int testMaxWithLclMin = std::max(greatestDist, std::abs(localMin - globalMax));
            int testMaxWithLclMax = std::max(greatestDist, std::abs(localMax - globalMin));

            greatestDist = std::max(std::max(greatestDist, testMaxWithLclMin), testMaxWithLclMax);

            globalMin = std::min(localMin, globalMin);
            globalMax = std::max(localMax, globalMax);
        }

        return greatestDist;
    }
};