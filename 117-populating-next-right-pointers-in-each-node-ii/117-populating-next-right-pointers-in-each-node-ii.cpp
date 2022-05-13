/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        Node *h = root;
        h->next = NULL;
        while(h!=NULL)
        {
            Node *prev = NULL;
            Node *nlh = NULL;
            while(h!=NULL)
            {
                if(h->left){
                    if(prev == NULL)
                    {
                        prev = nlh = h->left;
                    }
                    else
                    {
                        prev->next = h->left;
                        prev = prev ->next;
                    }
                }
                if(h->right)
                {
                    if(prev==NULL)
                    {
                        prev = nlh = h->right;
                    }
                    else
                    {
                        prev -> next = h-> right;
                        prev = prev->next;
                    }
                }
                h = h->next;
            }
            h = nlh;
            if(prev)
                prev->next = NULL;
        }
        return root;
    }
};

















/*
O(n) | O(1)
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;
        if(root == NULL) return root;
        q.push(root);
        while(q.empty()!=true)
        {
            int size = q.size();
            while(size>0)
            {
                Node *curr = q.front();
                q.pop();
                if(size == 1)
                    curr->next = NULL;
                else
                    curr->next = q.front();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                size--;
            }
        }
        return root;
    }
};
*/