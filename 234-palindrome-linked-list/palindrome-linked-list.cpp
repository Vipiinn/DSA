
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
        //farzi node
        ListNode *c = new ListNode(20);

        //deep copy of head
        ListNode* temp = head;
        ListNode* tempC = c;

        while(temp !=  NULL){
            ListNode* node = new ListNode(temp->val);
            tempC->next = node;
            temp = temp->next;
            tempC = tempC->next;
        }

        c = c->next;
        c = reverse(c);

        ListNode* a = head;
        ListNode* b = c;

        while(a != NULL){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};