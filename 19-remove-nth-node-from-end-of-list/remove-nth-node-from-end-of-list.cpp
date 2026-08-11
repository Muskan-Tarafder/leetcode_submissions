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
        ListNode* temp=head;
        ListNode* prev=NULL;
        int ele=0;
        while(temp){
            ele++;
            temp=temp->next;
        }
        if(n==ele){
            return head->next;
        }
        temp=head;
        int k=ele-n+1;
        ListNode* next=NULL;
        if(temp) next=temp->next;
        while(temp && k>1){
            prev=temp;
            temp=next;
            if(temp) next=temp->next;
            k--;
        }
        if(prev) prev->next=next;
        return head;

        
    }
};