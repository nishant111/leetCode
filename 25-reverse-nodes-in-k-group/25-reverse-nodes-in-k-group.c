/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;



struct ListNode* reverseKGroup(struct ListNode* head, int k){

    node *last = NULL;
    node *curr = head;
    node * prev = NULL;
    node *newEnd = curr;
    node *nxt;
    int i = 0;
    
    while(curr !=NULL)
    {
        //newEnd = prev;
        // check if there are k-1 nodes ahead
        node *temp;
        if(prev==NULL)
            temp = curr;
        else
            temp = prev;
        for(int i = 0;i<k-1 && temp!=NULL;i++)
        {
            temp = temp->next;
        }
        if(temp==NULL)
            break;
        
        while(i<k)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            i++;
        }
        if(last == NULL) head = prev;
        else 
        {
            last->next = prev;
        }
        newEnd->next = curr;
        last=newEnd;
        newEnd = curr;
        prev = curr;
        if(curr!=NULL)
            curr = curr->next;
        i=1;
    }
    return head;
}