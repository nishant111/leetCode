/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode * temp = head;
    struct ListNode * n;
    struct ListNode* prev = NULL;
    if (head== NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    while (temp->next != NULL)
    {
        n=temp->next;
        temp->next = prev;
        prev = temp;
        temp=n;
    }
    temp->next = prev;
    head = temp;
    return head;
}