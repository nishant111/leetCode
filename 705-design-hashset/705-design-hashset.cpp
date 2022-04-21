class node{
  public:
    int val;
    node *next;
};

class MyHashSet {
public:
    node *root;
    MyHashSet() {
        root = NULL;    
    }
    
    void add(int key) {
      if(!contains(key))
      {
        node *tmp = root;
        root=(node*)calloc(1,sizeof(node));
        root->val = key;
        root->next = tmp;
      }
    }
    
    void remove(int key) {
        node*curr = root;
        if(curr == NULL) return;
        if(curr->val == key)
        {
            node *tmp = root->next;
            free(root);
            root = tmp;
            return;
        }
        while(curr->next!= NULL)
        {
            if(curr->next->val == key)
            {
                node*tmp = curr->next->next;
                free(curr->next);
                curr->next = tmp;
                return;
            }
            curr = curr->next;
        }
        return;
    }
    
    bool contains(int key) {
        node*curr = root;
        while(curr)
        {
            if(curr->val == key)
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */