// queue.h //

#ifndef __QUEUE_H__
#define __QUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int QDATA;

typedef struct _node
{
  QDATA data;
  struct _node* next;
} NODE;

typedef struct _queue
{
  NODE* input;
  NODE* output;
  int num_node;
} Linked_queue;

typedef Linked_queue QUEUE;

void Init(QUEUE* pq);
int isEmpty(QUEUE* pq);

void Enque(QUEUE* pq, QDATA data);

QDATA Deque(QUEUE* pq);
QDATA Peek(QUEUE* pq);

#endif
