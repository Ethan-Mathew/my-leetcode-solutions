class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int sPtr = 0;
        int gPtr = 0;
        int satisfied = 0;

        while (gPtr < g.size() && sPtr < s.size()) {
            if (s[sPtr] >= g[gPtr]) {
                gPtr++; satisfied++;
            }

            sPtr++;
        }

        return satisfied;
    }
};