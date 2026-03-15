class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty()) {
            return;
        }
        
        if (nums1.size() == n) {
            nums1 = nums2;
            return;
        }

        int nums1Ptr = nums1.size() - nums2.size() - 1;
        int nums2Ptr = nums2.size() - 1;
        int fillPtr = nums1.size() - 1;

        while (nums2Ptr >= 0) {
            if (nums1Ptr >= 0 && nums1[nums1Ptr] >= nums2[nums2Ptr]) {
                nums1[fillPtr] = nums1[nums1Ptr];
                nums1Ptr--;
            } else {
                nums1[fillPtr] = nums2[nums2Ptr];
                nums2Ptr--;
            }

            fillPtr--;
        }
    }
};