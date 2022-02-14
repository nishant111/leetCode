// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively

Node * find(Node *root, int key)
{
    Node *curr = root;
    while(curr !=NULL)
    {
        if(key > curr -> key)
            curr = curr->right;
        else if(key < curr->key)
            curr = curr->left;
        else
        {
            return curr;
        }
    }
    return NULL;
}
Node* prede(Node *root, Node * &pre)
{
    Node *curr= root;
    while(curr != NULL)
    {
        if(curr -> right)
            curr=curr->right;
        else
            return curr;    
    }
}

Node* succe(Node *root, Node * &suc)
{
    Node *curr= root;
    while(curr != NULL)
    {
        if(curr -> left)
            curr=curr->right;
        else
            return curr;    
    }
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    //max in left is pre
    // min in right is suc
    
    /*Node* keyroot = find(root, key);
    if(keyroot == NULL) return; //didnt find key node
    pre = prede(keyroot->left, pre);
    suc = succe(keyroot->right, suc); */
    
    Node *curr = root;
    //successor
    while(curr !=NULL)
    {
        if(curr -> key > key)
        {
            //possible ans, is always better are compared to previous stored
            suc = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    curr = root;
    //predecessor
    while(curr != NULL)
    {
        if(curr->key < key )
        {
            //possible ans;
            pre = curr;
            curr = curr ->right;
        }
        else
        {
            curr = curr->left;
        }
        
    }
}
    
// Your code goes here

