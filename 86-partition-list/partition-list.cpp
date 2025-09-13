class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* a = new ListNode(200);
        ListNode* tempA = a;
        ListNode* b = new ListNode(500);
        ListNode* tempB = b;

        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL){
            if(temp->val < x){
                tempA->next = temp;
                tempA = tempA->next;
                temp = temp->next;
            }
            else{
                tempB->next = temp;
                tempB = tempB->next;
                temp = temp->next;
            }
        }

        if(temp != NULL && temp->val < x){
            tempA->next = temp;
            tempA = tempA->next; 
        }
        else{
            tempB->next = temp;  
            tempB = tempB->next;
        }

        tempA->next = NULL;
        tempB->next = NULL;

        tempA->next = b->next;
        return a->next;
    }
};