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
  ListNode*revereseLL(ListNode*head)
 {
     ListNode*next=NULL;
     ListNode*prev=NULL;
    ListNode*temp=head;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
 }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
           if (head == NULL || head->next == NULL)
            return true;
    
     
       
       ListNode*slow=head;
       ListNode*fast=head;
       while(fast!=NULL && fast->next!=NULL )
       {
         slow=slow->next;
         fast=fast->next->next;
       }
      
       if(fast!=NULL)
      {
        slow=slow->next;
      }
      ListNode*head1=revereseLL(slow);
      ListNode*temp=head;
      while(head1!=NULL)  
      {
        if(temp->val!=head1->val)
        {
            return false;
        
        }
        temp=temp->next;
        head1=head1->next;
      }
        
      return true;
    }
};