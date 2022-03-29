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
        unordered_map<Node*, Node*> m;
        Node *curr = head;
        while(curr)
        {
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->val = curr->val;
            tmp->random = NULL;
            tmp->next = NULL;
            m.insert({curr, tmp});
            curr = curr->next;
        }
        curr = head;
        while(curr)
        {
            if(curr -> next)
            {
                m[curr]->next = m[curr->next];
            }
            if(curr -> random)
            {
                m[curr] -> random = m[curr->random];
            }
            curr = curr->next;
        }
        return m[head];
        }
};