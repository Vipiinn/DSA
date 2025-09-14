
class Solution {
public:

    ListNode* reverseList(ListNode* head){
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

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* sNext = slow->next;
        slow->next = NULL;

        sNext = reverseList(sNext);

        //farzi node
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        ListNode* tempA = head;
        ListNode* tempB = sNext;

        while(tempA != NULL && tempB != NULL){
            tempC->next = tempA;
            tempC = tempC->next;
            tempA = tempA->next;
            tempC->next = tempB;
            tempC = tempC->next;
            tempB = tempB->next;
        }
        if(tempA != NULL) tempC->next = tempA;
        else tempC->next = tempB;
        
    }
};