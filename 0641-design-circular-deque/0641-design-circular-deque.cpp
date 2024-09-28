class MyCircularDeque {
public:
    class node{
        public:
        int val;
        node *left;
        node *right;
    };
    node * h;
    node * t;
    int size;
    int cap;
    MyCircularDeque(int k) {
        cap = k;
        size = 0;
        h = NULL;
        t = NULL;
    }
    void insertOnEmpty(int value, node **ptr){
        (*ptr) = new node();
        (*ptr)->val = value;
        (*ptr)->left = NULL;
        (*ptr)->right = NULL;
    }
    bool insertFront(int value) {
        if(size == cap)
            return false;
        if(h == NULL && t == NULL){
            insertOnEmpty(value, &h);
            t = h;
        }
        else{
            node *curr = new node();
            curr->val = value;
            curr->right = h;
            curr->left = NULL;
            h->left = curr;
            h = curr;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
         if(size == cap)
            return false;
         if(h == NULL && t == NULL){
            insertOnEmpty(value, &t);
            h = t;
        }
        else{
            node *curr = new node();
            curr->val = value;
            curr->left = t;
            curr->right = NULL;
            t->right = curr;
            t = curr;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0)
            return false;
        if(size == 1){
            h = NULL;
            t = NULL;
        }
        else{
            node *newHead = h->right;
            delete(h);
            h = newHead;
        }
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0)
            return false;
         if(size == 1){
            h = NULL;
            t = NULL;
        }
        else{
            node *newTail = t->left;
            delete(t);
            t = newTail;
        }
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0)
            return -1;
        return h->val;
    }
    
    int getRear() {
        if(size==0)
            return -1;
        return t->val;
    }
    
    bool isEmpty() {
         if(size==0)
             return true;
        return false;
    }
    
    bool isFull() {
        if(size == cap)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */