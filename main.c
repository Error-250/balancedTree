#include "tree.h"

int main(void) {
    struct treeNode *root;
    root = createTree( 9 );
    addTreeNode( 8, &root );
    addTreeNode( 7, &root );
    addTreeNode( 6, &root );
    addTreeNode( 5, &root );
    addTreeNode( 4, &root );
    addTreeNode( 3, &root );
    visitTree( root );
    return 0;
}