
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        ListNode* thead = new ListNode(100);
        ListNode* temp = thead;
        
        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
            else{
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
        }
        if(head1 != NULL){
            temp->next = head1;
        }
        else{
            temp->next = head2;
        }
        return thead->next;
    }
};