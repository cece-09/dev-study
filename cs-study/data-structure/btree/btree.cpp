#include <iostream>

#include "btree.hpp"

using namespace std;

/** constructor
 * @param int  _t    : degree of node
 * @param bool _leaf : if node is leaf
*/
TreeNode::TreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;

    keys = new int[2 * t - 1]; // create array
    C = new TreeNode *[2 * t]; // create array

    n = 0;
}

/** traverse starting with this node */
void TreeNode::traverse() {
    int i;
    for(i = 0; i < n; i++) {
        /* visit children's subtree
           where key is smaller than keys[i] */
        if(leaf == false) {
            C[i]->traverse();  
        }
        cout << " " << keys[i];
    }

    if(leaf == false) {
        /* visit last child where key is
           larger than all keys in node */
        C[i]->traverse();
    }
}

/* search for the key k */
TreeNode *TreeNode::search(int k) {
    int i = 0;
    /* find where keys[i] >= k */
    while (i < n && k > keys[i])
        i++; // 키 배열 탐색
    
    /* found */
    if(keys[i] == k)
        return this;
    
    if(leaf == true)
        return NULL;
    
    /* since keys[i] > k, continue
       searching in smaller subtree,
       where C[i] < keys[i] */
    return C[i]->search(k);
}


/* insert key in node */
void TreeNode::insertNonFull(int k) {
    int i = n - 1;
    if(leaf == true) {
        while(i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i]; // 한 칸씩 옆으로 옮김
            i--;
        }
        keys[i+1] = k;           // 오름차순 정렬해 삽입
        n++;
    } else {
        while(i >= 0 && keys[i] > k)
            i--;
        
        if(C[i+1]->n == 2 * t - 1) {
            splitChild(i+1, C[i+1]);
            if(keys[i+1] < k)
                i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

/** split child 
 * @param int       i : idx to split
 * @param TreeNode* y : node to split  
*/
void TreeNode::splitChild(int i, TreeNode *y) {
    // create new node
    TreeNode *z = new TreeNode(y->t, y->leaf);
    z->n = t - 1;

    // z->keys[0:t-1] = y->keys[t:2t]
    for(int j = 0; j < t - 1; j++) 
        z->keys[j] = y->keys[j + t];

    // z->C[0:t-1] = y->C[t:2t]
    if(y->leaf == false) {
        for(int j = 0; j < t; j++) {
            z->C[j] = y->C[j + t];
        }
    }

    y->n = t - 1;
    // find place to insert y
    for(int j = n; n >= i + 1; j--) 
        C[j + 1] = C[j];
    
    C[i + 1] = z;

    for(int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    
    keys[i] = y->keys[t - 1];
    n++;
}

/* constructor */
BTree::BTree(int temp) {
    root = NULL;
    t = temp;
}

void BTree::traverse() {
    if(root != NULL)
        root->traverse();
}

TreeNode* BTree::search(int k) {
    return (root == NULL) ? NULL : root->search(k);
}

/* insert key in tree */
void BTree::insert(int k) {
    if(root == NULL) {
        /* when node is root */
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if(root->n == 2 * t - 1) {
            /* if root node is full */
            TreeNode *s = new TreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if(s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}
