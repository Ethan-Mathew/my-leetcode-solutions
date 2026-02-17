class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> methods(n + 1, 0);
        methods[1] = 1;

        if (n > 1) {
            methods[2] = 2;
        }

        for (int i = 3; i <= n; i++) {
            methods[i] = methods[i - 1] + methods[i - 2];
        }

        return methods[n];
    }
};