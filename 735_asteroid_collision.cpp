class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> positiveAsteroids;
        std::vector<int> survivingAsteroids;

        for (int i{}; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                positiveAsteroids.push(asteroids[i]);
            } else {
                bool survived = true;

                while (!positiveAsteroids.empty()) {
                    if (positiveAsteroids.top() < std::abs(asteroids[i])) {
                        positiveAsteroids.pop();
                    } else if (positiveAsteroids.top() == std::abs(asteroids[i])) {
                        positiveAsteroids.pop();
                        survived = false;
                        break;
                    } else {
                        survived = false;
                        break;
                    }
                }

                if (survived) {
                    survivingAsteroids.push_back(asteroids[i]);
                }
            }
        }

        std::vector<int> survivingPositiveAsteroids;
        while (!positiveAsteroids.empty()) {
            survivingPositiveAsteroids.push_back(positiveAsteroids.top());
            positiveAsteroids.pop();
        }

        std::reverse(survivingPositiveAsteroids.begin(), survivingPositiveAsteroids.end());

        for (int num : survivingPositiveAsteroids) {
            survivingAsteroids.push_back(num);
        }

        return survivingAsteroids;
    }
};