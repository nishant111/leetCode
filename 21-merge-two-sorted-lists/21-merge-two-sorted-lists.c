/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *myhead = malloc(sizeof(struct ListNode));
    struct ListNode *sort = myhead;
    //struct ListNode *myhead;
    if(l1==NULL && l2==NULL)
        return NULL;
    /*
    if(l1==NULL || l2==NULL)
    {
        if(l1==NULL)
            sort = l2;
        else
            sort=l1;
    }
    if (l1 && l2)
    {
        if(l1->val <l2->val)
        {
            myhead = l1;
            sort=l1;
            l1 = l1->next;

        }
        else
        {
            myhead = l2;
            sort=l2;
            l2 =l2->next;
        }
    }*/
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val <=l2->val)
        {
            sort->next = l1;
            sort=sort->next;
            l1 = l1->next;
        }
        else if(l2->val <=l1->val)
        {
            sort->next= l2;
            sort = sort->next;
            l2 = l2->next;
        }
    }
    if(l1==NULL)
    {
        sort->next=l2;
    }
    else
    {    
        sort->next = l1;
    }    
    return myhead->next;
}