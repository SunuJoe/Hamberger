// hamberger.c //
// this is example of books. that is queing system example using
// simulation case. which is hamberger wating place to predict.

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <time.h>

#define CUSTOMER_COME 15

#define BUR_CHEESE 0
#define BUR_BEEF 1
#define BUR_CHIC 2

#define TERM_CHEESE 12
#define TERM_BEEF 15
#define TERM_CHIC 24

int room_scale = 10;

int main(int argc, char **argv)
{
  int makeProc = 0;
  int odr_cheese = 0, odr_beef = 0, odr_chic = 0;
  int sec;

  QUEUE q;
  Init(&q);

  srand(time(NULL));

  for(sec = 0; sec<3600; sec++)
  {
    if(sec % CUSTOMER_COME == 0)
    {
      switch(rand() % 3)
      {
        case BUR_CHEESE:
          Enque(&q, TERM_CHEESE);
          odr_cheese += 1;
          break;
        case BUR_BEEF:
          Enque(&q, TERM_BEEF);
          odr_beef += 1;
          break;
        case BUR_CHIC:
          Enque(&q, TERM_CHIC);
          odr_chic += 1;
          break;
      }
    }
    if(makeProc <= 0 && !isEmpty(&q))
    {
      makeProc = Deque(&q);
    }
    printf("%d ", q.num_node);
    makeProc--;
  }
  
  printf(" ---- The Result of Simulation ---- \n");
  printf(" cheese burger order numbers : %d\n", odr_cheese);
  printf(" beef burger order numbers : %d\n", odr_beef);
  printf(" chicken burger order numbers : %d\n",  odr_chic);
  printf(" rom size : %d\n", room_scale);

  return 0;
}


