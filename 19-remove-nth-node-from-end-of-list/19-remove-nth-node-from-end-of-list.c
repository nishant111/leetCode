/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode * tempRight = head;
    struct ListNode * tempLeft = head;
    if (n==1)
    {
        if(head->next == NULL)
            return NULL;
    }
    //setting the right temp ptr to n ahead of tempLeft;
    int i = 0;
    for(;(i<n) &&  (tempRight->next != NULL);i++)
    {
        tempRight = tempRight->next;     
    }
    while(tempRight->next!=NULL)
    {
        tempLeft=tempLeft->next;
        tempRight=tempRight->next;
    }
    // now tempLeft points to nth node from behind
    if(tempRight->next == NULL && i==n-1)
    {
        /* Boundary case
        * Ex [1,2,3] n = 3
        */
        return tempLeft->next;
    }
    
    //generic case
    struct ListNode *ptr=tempLeft->next;
    tempLeft->next = tempLeft->next->next;
    free(ptr); //preventing memory leak;
    return head;
}