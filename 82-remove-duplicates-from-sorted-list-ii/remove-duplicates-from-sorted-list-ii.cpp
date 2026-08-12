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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//     if(head==NULL || head->next==NULL) return head;
//     ListNode*temp=head->next;
//     ListNode*a=head;
//     ListNode*temp1=head;
//     int b;
//     while(a!=NULL)
//     {
//         if(a->val==temp->val)
//         {
//             b=a->val;
//           ListNode*c=temp;
//             temp=temp->next;
//             a->next=temp;
//             delete c;
//         }
//         else if(a->val==b)
//         {
//          ListNode*c=a;
//             a=temp;
//             temp1->next=a;
//             if(temp!=NULL) temp=temp->next;
//             if(a!=NULL && a!=NULL)
//             if(temp->val!=a->val)    temp1=a;
//             delete c;
//          }
//          else{
//             temp=temp->next;
//             a=a->next;
//             if(temp->val!=a->val)
//             temp1=temp1->next;
//          }
//     }
//     return head;
//     }
// };

// ----------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            if (prev->next->val == prev->next->next->val) {
                int duplicateVal = prev->next->val;
                
                while (prev->next != nullptr && prev->next->val == duplicateVal) {
                    prev->next = prev->next->next;
                }
            } else {
                
                prev = prev->next;
            }
        }

        return dummy.next;
    }
};
