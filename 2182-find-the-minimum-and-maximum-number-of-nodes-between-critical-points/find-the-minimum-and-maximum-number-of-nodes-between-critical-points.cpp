/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, prevCritical = -1;
        int minDistance = INT_MAX;
        int position = 2;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr && curr->next) {
            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first == -1) {
                    first = position;
                } else {
                    minDistance = min(minDistance, position - prevCritical);
                }

                prevCritical = position;
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        if (first == -1 || first == prevCritical) {
            return {-1, -1};
        }

        return {minDistance, prevCritical - first};
    }
};