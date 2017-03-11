#include "queue.h"

void enQueue( struct treeNode *value , struct queue *que ) {
    struct queueItem *tmp;
    tmp = (struct queueItem *)malloc(sizeof( struct queueItem ));
    tmp -> value = value;
    tmp -> next = NULL;
    if( que -> head == NULL ) {
        que -> head = tmp;
        que -> tail = tmp;
    } else {
        que -> tail -> next = tmp;
        que -> tail = tmp;
    }
    que -> size ++;
}

struct treeNode * deQueue( struct queue *que ) {
    struct treeNode *tmp;
    struct queueItem *freeItem;
    tmp = que -> head -> value;
    freeItem = que -> head;
    que -> head = freeItem -> next;
    free( freeItem );
    if( que -> head == NULL ) {
        que -> tail = NULL;
    }
    que -> size --;
    return tmp;
}