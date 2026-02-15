class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> days(temperatures.size(), 0);
        std::stack<std::pair<int, int>> temp_stack;

        temp_stack.push(std::pair{temperatures[0], 0});
                    // pair: <temperature, index>
        for (int i{1}; i < temperatures.size(); i++)
        {
            if (temperatures[i] <= temp_stack.top().first)
            {
                temp_stack.push(std::pair{temperatures[i], i});
                continue;
            }
            else
            {
                while (!temp_stack.empty())
                {
                    if (temp_stack.top().first < temperatures[i])
                    {
                        int temp = temp_stack.top().second;
                        temp_stack.pop();

                        days[temp] = i - temp;
                    }
                    else
                    {
                        break;
                    }
                }

                temp_stack.push(std::pair{temperatures[i], i});
            }
        }

        return days;
    }
};