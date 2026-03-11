class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> nums2Copy(nums2.size(), -1);
        std::stack<int> indices;
        int n = nums2.size();
        
        indices.push(0);
        for (int i{1}; i < n; i++) {
            while (!indices.empty()) {
                if (nums2[i] > nums2[indices.top()]) {
                    nums2Copy[indices.top()] = nums2[i];
                    indices.pop();
                } else {
                    break;
                }
            }

            indices.push(i);
        }

        std::unordered_map<int, int> nums2IndexMap;
        for (int i{}; i < n; i++) {
            nums2IndexMap[nums2[i]] = i;
        }

        n = nums1.size();
        std::vector<int> solutions(nums1.size(), -1);
        for (int i{}; i < n; i++) {
            solutions[i] = nums2Copy[nums2IndexMap[nums1[i]]];
        }

        return solutions;
    }
};