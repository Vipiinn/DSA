
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

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size() == 0) return NULL;

        while(arr.size() > 1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};