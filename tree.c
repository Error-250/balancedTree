#include "tree.h"

int getDeepth(struct treeNode *root) {
    if(root == NULL)
        return 0;
    return max(getDeepth( root -> leftchild ), getDeepth( root -> rightchild )) + 1;
}

struct treeNode * createTree(int value) {
    struct treeNode *tmp;
    tmp = malloc(sizeof(struct treeNode));
    tmp -> leftchild = NULL;
    tmp -> rightchild = NULL;
    tmp -> value = value;
    return tmp;
}

void addTreeNode(int value, struct treeNode* *root ) {
    struct treeNode *tmp;
    struct treeNode *tmproot;
    struct treeNode *rawroot;
    struct treeNode *useroot;
    rawroot = ( *root );
    useroot = ( *root );
    tmp = malloc(sizeof(struct treeNode));
    tmp -> leftchild = NULL;
    tmp -> rightchild = NULL;
    tmp -> value = value;
    tmproot = useroot;
    while( tmproot != NULL ) {
        useroot = tmproot;
        if( useroot -> value > value ) {
            tmproot = useroot -> leftchild;
        } else {
            tmproot = useroot -> rightchild;
        }
    }
    if( useroot -> value > value )
        useroot -> leftchild = tmp;
    else
        useroot -> rightchild = tmp;
    adjustTree( &rawroot );
    ( *root ) = rawroot;
}

void visitTree( struct treeNode *root ) {
    struct queue myque;
    struct treeNode *tmp;
    int i, j;
    int size;
    int space_head, space_in;
    myque.head = NULL;
    myque.size = 0;
    enQueue( root, &myque );
    while( myque.head != NULL ) {
        size = myque.size;
        for(i = 0;i < size;i++) {
            tmp = deQueue( &myque );
            if(i == 0) {
                space_head = (int)pow( 2.0, (double)getDeepth( tmp ) - 1);
                space_in = space_head * 2 - 1;
                for(j = 0;j < space_head;j++)
                    printf(" ");
            }
            if(tmp != NULL) {
                printf("%d", tmp -> value );
                for(j = 0;j < space_in;j++)
                    printf(" ");
                enQueue( tmp -> leftchild, &myque );
                enQueue( tmp -> rightchild, &myque );
            } else {
                printf(" ");
                for(j = 0;j < space_in;j++)
                    printf(" ");
            }
        }
        printf("\n");
    }
}