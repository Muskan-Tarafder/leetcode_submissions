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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dumm=new ListNode(0);
        ListNode* fast=dumm;
        ListNode* slow=dumm;
        dumm->next=head;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }

        while(fast){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* nxt=slow->next;
        if(nxt) slow->next=nxt->next;
        return dumm->next;
    }
};