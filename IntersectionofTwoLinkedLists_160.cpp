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
        if (!headA || !headB)
            return NULL;
        ListNode *pA = headA, *pB = headB;
        while (1) {
            if (pA == pB)
                return pA;
            if (pA->next && pB->next) {
                pA = pA->next;
                pB = pB->next;
            } else if (pA->next) {
                pA = pA->next;
                pB = headA;
                break;
            } else if (pB->next){
                pB = pB->next;
                pA = headB;
                break;
            } else {
                return NULL;
            }
        }
       while (1) {
           if (pA == pB)
               return pA;
           if (pA->next && pB->next) {
               pA = pA->next;
               pB = pB->next;
           } else if (pA->next) {
               pB = headA;
               pA = pA->next;
               break;
           } else {
               pB = pB->next;
               pA = headB;
               break;
           }
       }
      while (pA && pB) {
          if (pA == pB)
              return pA;
          pA = pA->next;
          pB = pB->next;
      } 
       return NULL; 
    }
};