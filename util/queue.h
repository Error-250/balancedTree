#ifndef __QUEUE__
#define __QUEUE__

#include <stdlib.h>
struct queueItem {
    struct treeNode *value;
    struct queueItem *next;
};

struct queue {
    struct queueItem *head;
    struct queueItem *tail;
    int size;
};
/*
    Enter queue
*/
void enQueue( struct treeNode *value , struct queue *que );
/*
    Out queue
*/
struct treeNode * deQueue( struct queue *que );
#endif