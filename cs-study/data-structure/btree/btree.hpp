// btree.hpp

class TreeNode {
    int *keys;       /* keys in node */
    int t;           /* minimum degree (n/2) */
    int n;           /* number of key */
    bool leaf;       /* if this is leaf node */
    TreeNode **C;    /* children nodes */

    public:
    TreeNode(int temp, bool bool_leaf);

    void insertNonFull(int k);
    void splitChild(int i, TreeNode *y);
    void traverse();

    TreeNode *search(int k);

    friend class BTree;
};

class BTree {
    TreeNode* root;
    int t;

    public:
    BTree(int temp);

    void traverse();
    TreeNode* search(int k);

    void insert(int k);
};
