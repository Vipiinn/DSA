//ROTATE LIST
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL  || k == 0) return head;

        ListNode* a = head;
        ListNode* b = head;
        ListNode* c = head;

        int len = 1;
        
        while(c->next != NULL){
            len++;
            c = c->next;
        }
        k = k%len;
        len = len - k;

        for(int i=1;i<len;i++){
            b = b->next;
        }

        c->next = head;
        head = b->next;
        b->next = NULL;

        return head;

    }
    
};