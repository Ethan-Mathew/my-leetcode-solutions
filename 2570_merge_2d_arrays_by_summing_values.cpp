class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int ptr1 = 0;
        int ptr2 = 0;
        std::vector<std::vector<int>> solutions;

        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                solutions.push_back(std::vector<int>{nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                solutions.push_back(std::vector<int>{nums1[ptr1][0], nums1[ptr1][1]});
                ptr1++;
            } else {
                solutions.push_back(std::vector<int>{nums2[ptr2][0], nums2[ptr2][1]});
                ptr2++;
            }
        }

        int ptrRemaining = (ptr1 >= nums1.size()) ? ptr2 : ptr1;
        std::vector<std::vector<int>>& remaining = (ptr1 >= nums1.size()) ? nums2 : nums1;

        for (int i{ptrRemaining}; i < remaining.size(); i++) {
            solutions.push_back(std::vector<int>{remaining[i][0], remaining[i][1]});
        }

        return solutions;       
    }
};