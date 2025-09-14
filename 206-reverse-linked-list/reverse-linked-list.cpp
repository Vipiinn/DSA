class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* Next = NULL;

        ListNode* current = head;

        while(current != NULL){
            Next = current->next;
            current->next = prev;
            prev = current;
            current = Next;
        }
        return prev;
    }
};