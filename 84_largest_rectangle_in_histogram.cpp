class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> heightStack;
        int maxArea = 0;

        for (int i{}; i < heights.size(); i++) {
            if (heightStack.empty()) {
                heightStack.push(std::pair<int, int>{heights[i], i});
                continue;
            }

            if (heightStack.top().first < heights[i]) {
                heightStack.push(std::pair<int, int>{heights[i], i});
                continue;
            }

            int setbackIndex;
            while (!heightStack.empty() && heightStack.top().first >= heights[i]) {
                setbackIndex = heightStack.top().second;
                int tempArea = (i - setbackIndex) * heightStack.top().first;
                maxArea = std::max(maxArea, tempArea);
                heightStack.pop();
            }
            heightStack.push(std::pair<int, int>{heights[i], setbackIndex});
        }

        while (!heightStack.empty()) {
            int tempArea = (heights.size() - heightStack.top().second) * heightStack.top().first;
            maxArea = std::max(maxArea, tempArea);
            heightStack.pop();
        }

        return maxArea;
    }
};
