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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        int ps = 0;
        unordered_map<int, ListNode *> mp;
        ListNode *start = new ListNode();
        start->next=head;
        ListNode *curr = head;
        mp[ps]=start;
        while(curr!=NULL)
        {
            ps += curr->val;
            if(mp.find(ps)==mp.end())
                mp[ps]=curr;
            else{
                 ListNode* prev = mp[ps];
                curr = prev->next;
                int p = ps + curr->val;
                while(p!=ps){
                    mp.erase(p);
                    curr=curr->next;
                    p+= curr->val;
                }
                prev->next = curr->next;
            }
            curr=curr->next;
        }
        return start->next;
    }
};