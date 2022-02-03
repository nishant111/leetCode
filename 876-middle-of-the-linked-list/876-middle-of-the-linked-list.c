/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* first = head;
    struct ListNode* second = first;
    while(second->next!= NULL && second->next->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
    }
    if(second->next==NULL)
        return first;
    else if(second->next->next==NULL)
        return first->next;
    else
        return NULL;
}