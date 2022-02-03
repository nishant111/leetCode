/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode list;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    list* head;
    head = calloc(1,sizeof(list));
    list *temp = head;
    while(l1->next != NULL && l2->next != NULL)
    {
        
        if((l1->val + l2->val  + temp->val)>9)
        {
            //perform carry
            int sum = (temp->val + l1->val + l2->val);
            temp->val = (sum) % 10;
            temp->next = calloc(1,sizeof(list));
            temp = temp->next;
            temp->val = 1;
            
        }
        else
        {
            temp->val += l1->val + l2->val;
            temp->next = calloc(1,sizeof(list));
            temp = temp->next;
        }
        l1 = l1->next;
        l2 = l2 -> next;
    }
    while(l1!=NULL || l2!= NULL)
    {
        if(l1!=NULL && l2!=NULL && (l1->val + l2->val  + temp->val)>9)
        {
            //perform carry
            int sum = (temp->val + l1->val + l2->val);
            temp->val = (sum) % 10;
            temp->next = calloc(1,sizeof(list));
            temp = temp->next;
            temp->val = 1;

        }
        else if(l1!=NULL && l2!=NULL && (l1->val + l2->val  + temp->val)<=9)
        {
            temp->val += l1->val + l2->val;
            temp->next = NULL;
            if(l1->next || l2->next)
            {
                temp->next = calloc(1,sizeof(list));
                temp = temp->next;
            }
        }
        else if(l2 == NULL && l1 !=NULL && (l1->val + temp->val)>9 )
        {
            //perform carry
            int sum = (temp->val + l1->val);
            temp->val = sum % 10;
            temp->next = calloc(1,sizeof(list));
            temp = temp->next;
            temp->val = 1;
        }
        else if(l2 == NULL && l1 !=NULL && (l1->val + temp->val)<=9 )
        {
            temp->val += l1->val;
            temp->next = NULL;
            if(l1->next)
            {
                temp->next = calloc(1,sizeof(list));
                temp = temp->next;
            }
        }
        else if(l1 == NULL && l2 !=NULL && (l2->val + temp->val)>9 )
        {
            //perform carry
            int sum = (temp->val + l2->val);
            temp->val = sum % 10;
            temp->next = calloc(1,sizeof(list));
            temp = temp->next;
            temp->val = 1;
        }
        else if(l1 == NULL && l2 !=NULL && (l2->val + temp->val)<=9 )
        {
            temp->val += l2->val;
            temp->next = NULL;
            if( l2->next)
            {
                temp->next = calloc(1,sizeof(list));
                temp = temp->next;
            }
        }
        
        if(l1 !=NULL)
            l1 = l1->next;
        if(l2!=NULL)
            l2 = l2->next;
    }
     
    
    //now reverse head
    
    return head;
}