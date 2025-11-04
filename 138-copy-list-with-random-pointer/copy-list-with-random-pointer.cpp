class Solution {
public:
    Node* copyRandomList(Node* head) {

        //step 1 -> make a deepcopy of List

        Node* dummy = new Node(0);
        Node* tempC = dummy;

        Node* temp = head;

        while(temp != NULL){
            Node* a = new Node(temp->val);
            tempC->next = a;

            temp = temp->next;
            tempC = tempC->next;
        }

        Node* b = dummy->next;;
        Node* a = head;

        //step2 : make a map of <original,duplicate>

        unordered_map<Node*,Node*>m;

        Node* tempa = a;
        Node* tempb = b;

        while(tempa != NULL){
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }

        for(auto x : m){
            Node* o = x.first;
            Node* d = x.second;

            if(o->random != NULL){
                Node* orandom = o->random;
                Node* drandom = m[o->random];
                d->random = drandom;
            }
        }
        return b;
    }
};