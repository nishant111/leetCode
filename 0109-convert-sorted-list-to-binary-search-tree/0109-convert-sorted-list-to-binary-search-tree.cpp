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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(int l , int r, vector<int> &arr) {
        if(l==r) {
            return new TreeNode(arr[l]);
        }
        if(l>r)
            return NULL;

        int mid = (l+r)/2;

        TreeNode *curr = new TreeNode(arr[mid]);

        curr->left = dfs(l , mid-1, arr);
        curr->right = dfs(mid+1, r, arr);
        return curr;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int> arr;
        ListNode *curr = head;
        while(curr) {
            arr.push_back(curr->val);
            curr=curr->next;
        }
        int l = 0;
        int r = arr.size()-1;
        return dfs(l,r,arr);

    }
};