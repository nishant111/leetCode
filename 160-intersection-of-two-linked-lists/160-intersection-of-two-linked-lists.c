/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode list;

#define MAX(a,b) (a>b?a:b);

void jump(list **l, int jump)
{
    int i = 1;
    while(i<=jump)
    {
        *l = (*l)->next;
        i++;
    }
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    list *a = headA;
    list *b = headB;
    int counta=0;
    int countb=0;
    while(a!=NULL)
    {
        counta++;
        a=a->next;
    }
    while(b!=NULL)
    {
        countb++;
        b=b->next;
    }
    a = headA;
    b=headB;
    // allign the starting points on both linked lists
    if(countb>counta)
    {
        int jumpval = countb-counta;
        jump(&b, jumpval);
    }
    else{
        int jumpval = counta-countb;
        jump(&a, jumpval);
    }
    // start iterating and find intersection
    while(a!=NULL || b!= NULL)
    {
        if(a==b)
        {
            return a;
        }
        a= a->next;
        b=b->next;
    }
    return NULL;
}