/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void swap(ListNode *node)
    {
        int tmp = node -> val;
        node->val = node->next->val;
        node -> next -> val = tmp;
    }
    void deleteNode(ListNode* node) {
        while(node->next->next!=NULL)
        {
            swap(node);
            node = node -> next;
            
        }
        swap(node);
        node->next = NULL;
    }
};