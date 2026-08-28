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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            function<bool(ListNode*, ListNode*)>
        > ak([](ListNode* as, ListNode* pe) {
            return as->val > pe->val;
        });

        for (auto l : lists) {
            if (l != nullptr) {
                ak.push(l);
            }
        }

        ListNode dummy(0);
        ListNode* as = &dummy;

        while (!ak.empty()) {
            ListNode* pe = ak.top();
            ak.pop();

            as->next = pe;
            as = as->next;

            if (pe->next != nullptr) {
                ak.push(pe->next);
            }
        }

        return dummy.next;
    }
};