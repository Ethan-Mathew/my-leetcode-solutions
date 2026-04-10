class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<std::pair<int, ListNode*>> valPtrPairs;

        for (ListNode* basePtr : lists) {
            while (basePtr) {
                valPtrPairs.emplace_back(basePtr->val, basePtr);
                basePtr = basePtr->next;
            }
        }

        if (valPtrPairs.size() == 0) {
            return nullptr;
        }

        std::sort(valPtrPairs.begin(), valPtrPairs.end());

        for (int i{1}; i < valPtrPairs.size(); i++) {
            valPtrPairs[i-1].second->next = valPtrPairs[i].second;
        }

        valPtrPairs[valPtrPairs.size() - 1].second->next = nullptr;

        return valPtrPairs[0].second;
    }
};