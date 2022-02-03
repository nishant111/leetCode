/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL)
        return false;
    if(head->next==NULL || head->next->next==NULL)
        return false;
    struct ListNode * first = head;
    struct ListNode * second = head->next->next;
    while(first!=NULL && second!=NULL && second->next !=NULL)
    {
        if(first == second)
            return true;
        first = first->next;
        second = second->next->next;
    }
    return false;
}