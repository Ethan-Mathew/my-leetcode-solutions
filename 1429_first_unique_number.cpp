class FirstUnique {
public:
    FirstUnique(vector<int>& nums) 
        : nums_{nums}
    {

        for (int num : nums) {
            if (unique_.find(num) != unique_.end() || duplicates_.find(num) != duplicates_.end()) {
                unique_.erase(num);
                duplicates_.insert(num);
            } else {
                unique_.insert(num);
            }

            for (int num : unique_) {
                std::cout << num << " ";
            }

            std::cout << '\n';

            for (int num : duplicates_) {
                std::cout << num << " ";
            }

            std::cout << '\n';
        }
    }
    
    int showFirstUnique() {
        for (int num : nums_) {
            if (unique_.find(num) != unique_.end()) {
                return num;
            }
        }
        
        return -1;
    }
    
    void add(int value) {
        nums_.push_back(value);

        if (unique_.find(value) != unique_.end() ||
            duplicates_.find(value) != duplicates_.end())
        {
            unique_.erase(value);
            duplicates_.insert(value);
        } else {
            unique_.insert(value);
        }
    }

private:
    std::vector<int> nums_;
    std::unordered_set<int> unique_;
    std::unordered_set<int> duplicates_;
};