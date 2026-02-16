class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> max_left(height.size(), 0);
        std::vector<int> max_right(height.size(), 0);

        max_left[0] = height[0];
        for (int i{1}; i < height.size(); i++) {
            max_left[i] = std::max(height[i], max_left[i - 1]);            
        }

        max_right[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            max_right[i] = std::max(height[i], max_right[i + 1]);
        }

        int water = 0;

        for (int i{}; i < height.size(); i++) {
            int quantity = std::min(max_left[i], max_right[i]) - height[i];
            if (quantity > 0) {
                water += quantity;
            }
        }
        
        return water;
    }
};