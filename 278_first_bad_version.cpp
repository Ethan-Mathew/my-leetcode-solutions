class Solution {
public:
    int firstBadVersion(int n) {
        uint64_t left = 1, right = n;

        while (left <= right) {
            uint64_t mid = (right + left) / 2;

            if (isBadVersion(left) && isBadVersion(mid)) {
                return left;
            } else if (isBadVersion(mid) && !isBadVersion(mid - 1)) {
                return mid;
            } else if (!isBadVersion(left) && !isBadVersion(mid)) {
                left = mid + 1;
            } else if (isBadVersion(mid) && isBadVersion(right)) {
                right = mid - 1;
            }
        }

        return -1;
    }
};