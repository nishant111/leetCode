/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *curr = head;
        vector<Node *> arr;
        // insert new nodes inbetween, and sets next pointer
        while(curr){
            arr.push_back(curr);
            Node *tmp = new Node(curr->val);
            // cache the next node, otherwise it will be lost
            Node *origNext = curr->next;
            curr->next = tmp;
            tmp->next = origNext;
            curr = curr->next->next;
        }
        
        //adjust random pointers
        curr=head;
        while(curr){
            curr->next->random = curr->random!=NULL ? curr->random->next: NULL ;
            curr = curr->next->next;
        }
        
        //remove extra nodes
        curr=head;
        Node * ret = curr->next;
        while(curr){
            Node *t = curr->next;
            curr->next = curr->next->next;
            if(t->next)
                t->next = t->next->next;
            else
                t->next = NULL;
            curr = curr->next;
        }
        return ret;
    }
    
    
    
};