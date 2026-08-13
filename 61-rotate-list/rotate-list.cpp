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
 int lenght(ListNode*head)
 {
    ListNode*temp=head;
    int l=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        l++;
    }
    return l;
 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL) return head;
     ListNode*temp=head;
     ListNode*a=temp;
     int l=lenght(head);
     k=k%l;
     for(int i=0;i<k;i++)
     {
        temp=head;
       while(temp->next!=NULL)
     {
        a=temp;
        temp=temp->next;
     }
     a->next=NULL;
     temp->next=head;
     head=temp;
     }
    return head;
    }
};