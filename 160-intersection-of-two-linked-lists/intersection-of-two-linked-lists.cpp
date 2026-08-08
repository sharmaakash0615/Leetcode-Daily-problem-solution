/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   if(headA==NULL || headB==NULL) return NULL;
    ListNode *temp1=headA; 
    ListNode *temp2=headB;
    int cnt1=0;
    int cnt2=0;
   while(temp1!=NULL)
   {
    cnt1++;
    temp1=temp1->next;
   }
    while(temp2!=NULL)
   {
    cnt2++;
    temp2=temp2->next;
   }
   temp1=headA; 
   temp2=headB;
   if(cnt1>cnt2)
   {
    int x=cnt1-cnt2;
    int i=0;
    while(i<x)
    {
      temp1=temp1->next;
      i++;
    }
   }

    else{
         int x=cnt2-cnt1;
         int i=0;
    while(i<x)
     {
      temp2=temp2->next;
      i++;
     }
    }

 while(temp1!=temp2)
 {
    temp1=temp1->next;
    temp2=temp2->next;

 }
 
return temp1;
    }
};