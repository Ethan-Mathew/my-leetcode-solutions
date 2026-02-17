class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> dpCost(cost.size(), 0);
        
        int last = cost.size() - 1;

        dpCost[last] = cost[last];
        dpCost[last - 1] = cost[last - 1];

        for (int i{last - 2}; i >= 0; i--) {
            dpCost[i] = cost[i] + std::min(dpCost[i + 1], dpCost[i + 2]);
        }

        return std::min(dpCost[0], dpCost[1]);
    }
};