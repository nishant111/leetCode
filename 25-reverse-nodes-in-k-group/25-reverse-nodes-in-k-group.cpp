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
    int gcount = 0;
    ListNode *reverse(ListNode *curr, int k)
    {
        ListNode *prev = NULL;
        ListNode *end;
        ListNode *next;
        int count = 0;
        ListNode* tmpcurr = curr;
        int nodecount=0;
        while(tmpcurr)
        {
            gcount++;
            nodecount++;
            tmpcurr = tmpcurr->next;
            if(nodecount == k)
                break;
        }
        if(nodecount <k) return curr;
        while(curr)
        {
            gcount++;
            if(count == 0) end = curr;
            next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
            if(count == k)
            {
                end->next = reverse(curr,k);
                break;
            }
        }
        return prev;
    
        
        
        
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        /*if(curr == NULL) return NULL;
        ListNode *prev = NULL;
        ListNode *start = curr;
        ListNode *next;
        int count = 1;
        //count number of nodes here
        while(curr!=NULL && count <k)
        {
            curr = curr-> next;
            count++;
        }
        if(curr == NULL && count<=k) return start;
        curr = start;
        count = 0;
        
        while(count <k && curr)
        {
            next = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count ++;
        }
        start -> next = reverse(curr, k);
        return prev;*/
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * curr = head;
        ListNode * ans = reverse(curr, k);
        
        cout<<"count is" <<gcount;
        return ans;
    }
};