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
        ListNode *a = headA;
        ListNode *b = headB;
        
        // corner cases
        if(a==b)return a;
        if(a==NULL)return a;
        if(b==NULL)return b;
        

        int temp  = 0;
        
        // in the first traversal make a and b pointers switch after reaching the ends
        while(1)
        {
            if(a==NULL)
            {
                a=headB;
                temp++;
            }
            if(b==NULL)
            {
                b=headA;
                temp++;
            }
            if(temp==2)break;
            a=a->next;
            b=b->next;
        }

        ListNode *ans;
        ans=NULL;
        //If they meet break and return the pointer
        while(a!=NULL && b!=NULL)
        {
            if(a==b)
            {
                ans = a;
                break;
            }
            if(a->next==NULL ||b->next==NULL)break;
            a=a->next;
            b=b->next;
        }

        return ans;
        
    }
};
