/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode list;
    

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    // find out last and new end
    if(head->next == NULL || head == NULL ||left==right) return head;
    list *curr = head;
    list *prev = NULL;
    list *nxt = NULL;
    list *last = NULL;
    list *newEnd= NULL;
    // skip left-1 nodes
    int i=0;
    while(i<(left-1) && curr!=NULL)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    printf("curr->val is %d", curr->val);
    // now curr is the left-1;
    last = prev;
    newEnd = curr;
    prev = curr;
    curr = curr->next;
    i = 0;
    while(i<(right-left+1)-1 && curr !=NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        i++;
    }
    if(last!=NULL)
        last->next = prev;
    else head=prev;
    newEnd->next = curr;
    return head;
}