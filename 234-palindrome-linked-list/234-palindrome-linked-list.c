/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
bool isPalindrome(struct ListNode* head){
    \/* try reverssing the linked list and then compare to reduce the memory requirements *\/
    
    struct ListNode * temp = head;
    int size = sizeof(int);
    if(head==NULL)
        return true;
    int *arr=malloc(100000*sizeof(int));
    arr[0] = head->val;
    temp=temp->next;
    int i =1;
    while(temp!=NULL)
    {
        size+=sizeof(int);
        //arr = realloc(arr, size); // memory leak if realloc fails
        arr[i] = temp->val;
        i++;
        temp=temp->next;
        
    }
    
    printf("Arr[0] is %d", arr[0]);
    int left = 0;int right = i-1; 
    for(;left<right;left++,right--)
    {
        if(arr[left]!=arr[right])
            return false;
    }
    return true;

}*/

typedef struct ListNode node;

node *reverse(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *nxt=NULL;
    while (curr!= NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head){
    //find middle
    if(head == NULL || head->next ==NULL) return true;
    node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast -> next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *temp=head;
    while(temp->next != slow)
    {
        temp = temp->next;
    }
    temp = reverse(slow);
    node *origTemp = temp;
    node *newHead = head;
    while(temp !=NULL && newHead!= origTemp)
    {
        if(newHead->val != temp->val)
            return false;
        newHead = newHead->next;
        temp = temp->next;
    }
    return true;
}