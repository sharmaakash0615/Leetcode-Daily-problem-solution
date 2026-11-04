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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return;

        ListNode* ak = head;
        ListNode* sh = head;

        while(sh->next != NULL && sh->next->next != NULL) {
            ak = ak->next;
            sh = sh->next->next;
        }

        ListNode* gh = ak->next;
        ak->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = gh;

        while(curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ak = head;
        sh = prev;

        while(sh != NULL) {
            ListNode* temp1 = ak->next;
            ListNode* temp2 = sh->next;

            ak->next = sh;
            sh->next = temp1;

            ak = temp1;
            sh = temp2;
        }
    }
};