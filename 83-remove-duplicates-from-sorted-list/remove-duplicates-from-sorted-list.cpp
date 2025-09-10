
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode* temp = head;
        ListNode* temp1 = head->next;

        while(temp1 != NULL){
            while(temp1 != NULL && temp->val == temp1->val){
                temp1 = temp1->next;
            }
            temp->next = temp1;
            temp = temp->next;
        }
        return head;
    }
};