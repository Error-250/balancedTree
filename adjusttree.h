#ifndef __ADJUST__
#define __ADJUST__

#include "tree.h"
int max(int a, int b);

void adjustAVLTree( struct treeNode* *root, int mod );

void adjustTree( struct treeNode* *root );

#endif