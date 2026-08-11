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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
         ListNode*temp=head->next;
         ListNode*a=head;
         while(temp!=NULL)
         {
            if(temp->val==a->val)
            {
               ListNode*b=temp;
              a->next=temp->next;
              temp=temp->next;
              delete b;
            }
            else{
                temp=temp->next;
                a=a->next;
            }
         }

    return head;
    }
};