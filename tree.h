#ifndef __TREE__
#define __TREE__

#include "util/queue.h"
#include "adjusttree.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
/*
    Tree Node
*/
struct treeNode {
    int value;
    struct treeNode *leftchild;
    struct treeNode *rightchild;
};
/*
    Get the deepth of a tree;
*/
int getDeepth(struct treeNode *root);
/*
    Create a tree
*/
struct treeNode * createTree(int value);
/*
    Add a tree_node to a tree
*/
void addTreeNode(int value, struct treeNode* *root );
/*
    Print a tree prettily
*/
void visitTree( struct treeNode *root );
#endif