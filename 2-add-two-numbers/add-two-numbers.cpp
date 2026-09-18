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
    ListNode* reverseList(ListNode* node){
        ListNode* prev=NULL;
        ListNode* curr=node;
        ListNode* nxt=NULL;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first=l1;
        ListNode* second=l2;

        int carry=0;
        ListNode* temp1=first;
        ListNode* temp2=second;
        ListNode* ans=new ListNode(-1);
        ListNode* hold=ans;
        while(temp1 && temp2){
            int sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            cout<<temp1->val<<"+"<<temp2->val<<" "<<sum%10<<" ";
            temp1=temp1->next;
            temp2=temp2->next;
            ans=ans->next;
        }
        while(temp1){
            int sum=temp1->val+carry;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            cout<<sum%10<<" ";
            temp1=temp1->next;
            ans=ans->next;
        }
        while(temp2){
            int sum=temp2->val+carry;
            carry=sum/10;
            ans->next=new ListNode(sum%10);
            cout<<sum%10<<" ";
            temp2=temp2->next;
            ans=ans->next;
        }
        if(carry!=0){
            ans->next=new ListNode(carry);
            cout<<carry<<" ";
        }
        // ans=reverseList(hold->next);
        return hold->next;

    }
};