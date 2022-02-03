/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* temp = NULL;
    temp = node;
    while(temp->next->next != NULL) //iterating till the second last node
    {
        int tempVal = temp->val;
        temp->val = temp->next->val;
        temp->next->val = tempVal;
        temp=temp->next;
    }
    temp->val = temp->next->val;
    free(temp->next);
    temp->next = NULL;
}