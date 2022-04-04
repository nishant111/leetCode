/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void swap(ListNode * targFirst, ListNode *targSecond)
    {
        int tmp = targFirst->val;
        targFirst->val = targSecond->val;
        targSecond->val = tmp;
        return;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode * left = head;
        ListNode * right = head;
        int count = 1;
        ListNode* targFirst;
        while(count<=k &&right->next !=NULL)
        {
            if(count == k)
            {
                targFirst = right;
            }
            right=right->next;
            count++;
            
        }
        if(right ->next == NULL && k == count)
        {
            swap(head, right);
            return head;
        }
        while(right->next!=NULL)
        {
            left = left->next;
            right = right ->next;
        }
        
        //swap
        swap(targFirst, left->next );
        return head;
    }
};