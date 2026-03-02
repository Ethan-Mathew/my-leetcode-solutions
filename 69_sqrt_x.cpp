class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int left = 0;
        int right = x;

        while (left <= right) {
            long mid = (right + left) / 2;
            long squared = mid * mid;
            long nextSquared = (mid + 1) * (mid + 1);

            if (squared == x) {
                return mid;
            } else if (squared < x && nextSquared > x) {
                return mid;
            } else if (squared < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};