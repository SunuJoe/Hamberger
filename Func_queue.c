// Func_queue.c //
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

extern int room_scale;

void Init(QUEUE* pq)
{
  pq->input = NULL;
  pq->output = NULL;
  pq->num_node = 0;
}

int isEmpty(QUEUE* pq)
{
  if(pq->output == NULL)
    return TRUE;
  else
    return FALSE;
}

void Enque(QUEUE* pq, QDATA data)
{
  if(pq->num_node > room_scale)
  {
    printf("Error Queue is over 100!\n");
    exit(-1);
  }

  NODE* newNode = (NODE*)malloc(sizeof(NODE));
  newNode->data = data;
  newNode->next = NULL;

  if(pq->output == NULL)
  {
    pq->output = newNode;
    pq->input = newNode;
    pq->num_node++;
  }
  else
  {
    newNode->next = pq->input->next;
    pq->input->next = newNode;
    pq->input = newNode;
    pq->num_node++;
  }
}

QDATA Deque(QUEUE* pq)
{
  if(isEmpty(pq))
  {
    printf("Queue is Empety\n");
    exit(-1);
  }
  else
  {
    NODE* temp = pq->output;
    QDATA temp_data = pq->output->data;

    pq->output = pq->output->next;
    free(temp);
    pq->num_node--; 
    return temp_data;
  }
}

QDATA Peek(QUEUE* pq)
{
  if(isEmpty(pq))
  {
    printf("QUEUE is Empety!!\n");
    exit(-1);
  }
  else
  {
    return pq->output->data;  
  }
}
