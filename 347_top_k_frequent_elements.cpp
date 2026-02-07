class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency_table;

        for (int& num : nums)
        {
            frequency_table[num]++;
        }

        std::priority_queue<std::pair<int,int>> max_heap;

        for (auto& kv : frequency_table)
        {
            max_heap.push(std::pair{kv.second, kv.first});
        }

        vector<int> solutions;

        for (int i{}; i < k; i++)
        {
            int num = (max_heap.top()).second;
            max_heap.pop();

            solutions.push_back(num);
        }

        return solutions;
    }
};