#include "adjusttree.h"

int max(int a, int b) {
    if ( a > b )
        return a;
    return b;
}

void adjustAVLTree( struct treeNode* *root, int mod ) {
    struct treeNode *target;
    struct treeNode *source;
    struct treeNode *tmproot;
    struct treeNode *tmpchild;
    source = ( *root );
    tmpchild = NULL;
    if( mod == 0 ) { // 调整左边
        target = source -> leftchild;
        tmproot = target -> rightchild;
        if( tmproot != NULL ) {
            tmpchild = tmproot;
        }
        while( tmpchild != NULL ) {
            tmproot = tmpchild;
            if( tmproot -> value > source -> value) {
                tmpchild = tmproot -> leftchild;
            } else {
                tmpchild = tmproot -> rightchild;
            }
        }
        if( tmproot == NULL ) {
            target -> rightchild = source;
        } else {
            if( tmproot -> value > source -> value ) {
                tmproot -> leftchild = source;
            } else {
                tmproot -> rightchild = source;
            }
        }
        source -> leftchild = NULL;
    } else {
        target = source -> rightchild;
        tmproot = target -> leftchild;
        if( tmproot != NULL ) {
            tmpchild = tmproot;
        }
        while( tmpchild != NULL ) {
            tmproot = tmpchild;
            if( tmproot -> value > source -> value) {
                tmpchild = tmproot -> leftchild;
            } else {
                tmpchild = tmproot -> rightchild;
            }
        }
        if( tmproot == NULL ) {
            target -> leftchild = source;
        } else {
            if( tmproot -> value > source -> value ) {
                tmproot -> leftchild = source;
            } else {
                tmproot -> rightchild = source;
            }
        }
        source -> rightchild = NULL;
    }
    ( *root ) = target;
}

void adjustTree( struct treeNode* *root ) {
    int ldeep, rdeep;
    if((*root) != NULL) {
        ldeep = getDeepth( ( *root ) -> leftchild );
        rdeep = getDeepth( ( *root ) -> rightchild );
        switch( ldeep - rdeep ) {
            case 2:
                // 左边多
                adjustAVLTree( root, 0 );
                break;
            case -2:
                // 右边多
                adjustAVLTree( root, 1 );
                break;
        }
        adjustTree( &(( *root ) -> leftchild ) );
        adjustTree( &(( *root ) -> rightchild ) );
    }
}