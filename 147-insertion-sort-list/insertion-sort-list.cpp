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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5001);

        ListNode* ak = head;

        while(ak != NULL) {
            ListNode* sh = ak->next;
            ListNode* gh = dummy;

            while(gh->next != NULL && gh->next->val <= ak->val) {
                gh = gh->next;
            }

            ak->next = gh->next;
            gh->next = ak;

            ak = sh;
        }

        return dummy->next;
    }
};