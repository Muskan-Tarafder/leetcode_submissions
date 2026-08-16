class Solution {
public:
    ListNode* solve(ListNode* prev, ListNode* temp) {
        ListNode* nxt = NULL;
        ListNode* p = prev;
        ListNode* t = temp;

        int k = 2;

        while (k > 0 && t) {
            nxt = t->next;
            t->next = p;
            p = t;
            t = nxt;
            k--;
        }

        // p = new head of this pair
        // temp = new tail of this pair
        // t = node after this pair

        if (prev)
            prev->next = p;

        temp->next = t;

        return temp;
    }

    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;

        int k = 2;

        // First pair
        while (k > 0 && temp) {
            nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
            k--;
        }

        // prev is new head
        head = prev;

        // temp is the node after first pair
        // old head is now the tail of first pair
        ListNode* prev2 = head->next;

        // Connect tail of first pair to remaining list
        prev2->next = temp;

        while (temp && temp->next) {
            prev2 = solve(prev2, temp);
            temp = prev2->next;
        }

        return head;
    }
};