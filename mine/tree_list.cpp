#include <cstddef>
struct node {
    int data;
    struct node* small;
    struct node* large;
};


static void join(node* left, node* right){
    left->large = right;
    right->small = left;
}

static node* append(node* left, node* right){
    node *alist, *blist;

    if(!left)
        return right;
    if(!right)
        return left;

    alist = left->small;
    blist = right->small;

    join(alist, right);
    join(blist, left);

    return left;
}

static node* tree_list(node* root){
    node* alist, *blist;

    if(!root)
        return NULL;

    alist = tree_list(root->small);
    blist = tree_list(root->large);

    root->small = root;
    root->large = root;

    alist = append(alist, root);
    alist = append(alist, blist);

    return alist;
}
