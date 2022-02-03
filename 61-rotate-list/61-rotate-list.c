/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head ==NULL || head->next ==NULL) return head;
    //find count
    int count = 0;
    node *curr =head;
    while(curr!=NULL)
    {
        count++;
        curr=curr->next;
    }
    printf("count is %d\n", count);
    int jump = (k%count);
    printf("jump is %d\n", jump);
    node * last=head;
    curr=head;
    // take last k times ahead of curr
    for(int i = 0;i<jump;i++)
    {
        last = last->next;
    }
    printf("last k times ahead is on %d\n", last->val);
    // move curr and last simultaneously
    while(last->next!=NULL)
    {
        curr = curr->next;
        last =last->next;
    }
    // make adjustments bringing the segment ahead
    printf("last is on %d\n", last->val);
    printf("curr in on %d\n", curr->val);
    last->next = head;
    head = curr->next;
    curr->next = NULL;
    return head;
}