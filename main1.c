// main1.c //

#include <stdio.h>
#include "queue.h"

int main(int argc, char **argv)
{
  QUEUE q;
  QDATA val;

  Init(&q);

  Enque(&q, 1);
  Enque(&q, 2);
  Enque(&q, 3);
  Enque(&q, 4);
  Enque(&q, 5);

  while(!isEmpty(&q))
  {
    val = Deque(&q);
    printf("delete %d\n", val);
  }
  return 0;
}
