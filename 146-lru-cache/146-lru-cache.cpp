#include <bits/stdc++.h>
using namespace std;


class LRUCache {

public:
    class node{
    public:
        int val;
        int key; //usefull while eraseing the tail elem from map
        node *left;
        node *right;
        
    };
    unordered_map <int, node *> m;
    node *head = (node*)malloc(sizeof(node));
    node *tail= (node*)malloc(sizeof(node));
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->right = tail;
        tail ->left = head;
    }
    
    void bringToFront(node *target)
    {
        target -> left->right = target->right;
        target ->right ->left = target->left;
        target->right = head->right;
        head->right->left= target;
        target ->left= head;
        head->right = target;
    }
    
    int get(int key) {
        //bring to the accessed node to the front in dll;
        if(m.find(key) != m.end())
        {
            // if key  exist return val
             node *target = m[key]; 
            bringToFront(target);
            return (target->val);
        }
        return -1;
    }
    
    void insertAtFront(int key, int val)
    {
        node *curr = (node*)malloc(sizeof(node));
        curr ->val = val;
        curr -> key = key;
        head->right ->left = curr;
        curr->right = head->right;
        curr->left = head;
        head->right = curr;
        m[key] = curr;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            //key existed this is an update bring node to front
                node *target = m[key];
                target->key = key;
                target->val = value;
                //cout<<"Updating "<<key <<"-" << value<<"\n";
                if(target->left !=head)
                {
                    //cout<<"Bring to the front "<<target->key <<"-" << target->val<<"\n";
                    bringToFront(target);
                }
        }
        else if(m.size() == cap)
        {
            /* key does not exist and capacity reached, Now either
             * Delete last and insert new at the beginning
             * Or, update key/value in the last and bring that to the front */
            //cout<<"putting "<<key <<"-" << value<<"\n";
            //cout <<"reached capacity, Resizing and pushing "<< value <<"\n" ;
            //free the last node and adjust pointers and remove entry in map
            m.erase(tail->left->key);
            node *temp = tail->left;
            temp -> val = value;
            temp->key = key;
            //free(temp);
            // remove entry from the map as well
            if(temp->left!=head)
                bringToFront(temp);
            m[key] = temp;
        }
        else
        {
            // insert at the end in dll and update map
            //cout<<"putting "<<key <<"-" << value<<"\n";
            insertAtFront(key, value);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */