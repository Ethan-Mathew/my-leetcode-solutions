class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> score;

        for (auto& s : operations)
        {
            if (s == "C")
            {
                score.pop();
            }
            else if (s == "D")
            {
                score.push(score.top() * 2);
            }
            else if (s == "+")
            {
                int temp = score.top();
                score.pop();
                int doubled = score.top() + temp;
                score.push(temp);
                score.push(doubled);
            }
            else
            {
                score.push(std::stoi(s));
            }
        }

        int total = 0;
        while (!score.empty())
        {
            total += score.top();
            score.pop();
        }

        return total;
    }
};