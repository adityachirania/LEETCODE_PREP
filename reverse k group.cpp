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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head,*prev=NULL,*nex=NULL;
        int count=0;
        while(count<k && cur!=NULL)
        {
            cur=cur->next;
            count++;
        }
        // if length < k then leave as it is 
        if(count<k)
            return head;
        cur=head;
        count=0;
        while(cur!=NULL && count<k)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
            count++;
        }
        if(nex!=NULL)
            head->next=reverseKGroup(nex,k);
        return prev;
    }
};
