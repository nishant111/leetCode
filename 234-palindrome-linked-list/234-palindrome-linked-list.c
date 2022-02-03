/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    /* try reverssing the linked list and then compare to reduce the memory requirements */
    
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

}