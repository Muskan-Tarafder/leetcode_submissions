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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* odd=NULL;
        ListNode* even=NULL;
        ListNode* evenhead=NULL;
        ListNode* temp=head;
        while(temp){
            if(odd==NULL){
                odd=temp;
            }else{
                odd->next=temp;
                odd=odd->next;
            }
            temp=temp->next;
            if(temp){
                if(even==NULL){
                    even=temp;
                    evenhead=even;
                }else{
                    even->next=temp;
                    even=even->next;
                }
                temp=temp->next;
            }
            else{
                break;
            }
        }
        if(even)even->next=NULL;
        if(odd)odd->next=evenhead;
        return head;

    }
};