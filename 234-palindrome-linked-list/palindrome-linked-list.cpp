
class Solution {
public:

    ListNode* reverse(ListNode* head){
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

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* sNext = slow->next;
        slow->next = NULL;

        sNext = reverse(sNext);
        while(sNext != NULL){
            if(head->val != sNext->val) return false;
            sNext = sNext->next;
            head = head->next;
        }
        return true;
    }
};