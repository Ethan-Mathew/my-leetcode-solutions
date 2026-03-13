class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int,double>> posTOA;
        for (int i{}; i < position.size(); i++) {
            double timeToArrive = (target - position[i]) / static_cast<double>(speed[i]);
            posTOA.push_back(std::pair<int,double>{position[i], timeToArrive});
        }

        std::sort(posTOA.begin(), posTOA.end());
        
        int numFleets = 1;
        //double bottleneck = posTOA[posTOA.size() - 1].second;
        std::cout << posTOA[posTOA.size() - 1].first << ' ' << posTOA[posTOA.size() - 1].second << '\n';
        
        for (int i = (posTOA.size() - 2); i >= 0; i--) {
            //std::cout << posTOA[i].first << ' ' << posTOA[i].second << ' ' << bottleneck << '\n';
            if (posTOA[i].second > posTOA[i + 1].second) {
                numFleets++;
            } else {
                posTOA[i].second = posTOA[i + 1].second;
            }
        }

        return numFleets;
    }
};