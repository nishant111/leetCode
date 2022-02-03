/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

typedef struct Node node;
    
/*void push(node* stack, node* left, node* right, int* top)
{
    if(left !=NULL)
    {
        (*top)++;
        stack[(*top)] = left;
    }
    if(right !=NULL)
    {
        (*top)++;
        stack[*top] = right;
    }
}
*/
struct Node* connect(struct Node* root) 
{
    node* stack[5000]={NULL};
    int top = 0;
    int curr = 0;
    if(root!=NULL)
    {
        stack[0] = root;
    }
    else
    {
        return NULL;
    }
    
    int currRoot=0;;
    node *myRoot = stack[currRoot];
    // getting level order 
    while (myRoot!=NULL)
    {
        //push(stack, myRoot->left, myRoot->right, &top);
        if(myRoot->left!=NULL)
        {
            top++;
            stack[top] = myRoot->left;
        }
        if(myRoot->right!=NULL)
        {
            top++;
            stack[top] = myRoot->right;
        }
        currRoot ++;
        myRoot = stack[currRoot];
    }
    // setting all right pointers;
    for(int i = 0;i<top;i++)
    {
        stack[i]->next =  stack[i+1];
    }
    // setting all right nodes's right to NULL
    myRoot = root;
    for(;myRoot!=NULL;myRoot=myRoot->right)
    {
        myRoot->next=NULL;
    }
	return root;
}