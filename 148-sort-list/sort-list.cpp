class Solution {
public:

    ListNode* mergeList(ListNode* List1 , ListNode* List2){

        ListNode* nHead = new ListNode(100);
        ListNode* temp = nHead;

        while(List1 != NULL && List2 != NULL){
            if(List1->val <= List2->val){
                temp->next = List1;
                temp = temp->next;
                List1 = List1->next;
            }
            else{
                temp->next = List2;
                temp = temp->next;
                List2 = List2->next;
            }
        }
        if(List2 != NULL){
            temp->next = List2;
        }
        else{
            temp->next = List1;
        }
        return nHead->next;
    }

    ListNode* mergeSort(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;
        
        //base case
        if(head->next == NULL){
            return head;
        }

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* sNext = slow->next;
        slow->next = NULL;

        ListNode* a = mergeSort(head);
        ListNode* b = mergeSort(sNext);

        ListNode* c = mergeList(a , b);
        return c;

    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        
        return mergeSort(head);
    }
};