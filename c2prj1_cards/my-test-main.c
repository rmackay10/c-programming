#include "cards.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  card_t c;
  //   char c3[20];
  //  char * c2;
   hand_ranking_t myRank = STRAIGHT_FLUSH;
    int n;
    int n1;
    //  printf("input 2-14 for your card value ");
    //    fgets(c3,14,stdin);
    //  n=atoi(c3);
    //  printf("input an integer for your suit (0-3)SPADES, HEARTS, DIAMONDS, CLUBS) ");
    //   fgets(c2,20,stdin);
    //  printf ("string is %s \n", c2);
    //  n1=atoi(c2);
    //  fgets (n,1024,stdin);
      for (n1=0;n1<4; n1++) {
	printf("letter for card and suit ");
    for (n=2;n<15; n++) {  
      c.value=n;
  c.suit=n1;
  assert_card_valid(c);
  //  char c1=suit_letter(c);
  //char c4=value_letter(c);
  print_card(c);
  // printf(" %c%c ",c4,c1);
    }
  printf("\n");    
}
      printf("ranking case 0 to 9 ");
          for (myRank=0; myRank<10; myRank++) {
      printf("%s ",  ranking_to_string(myRank));
      }
	  printf("\n");
	  printf("card from letters \n");
	  c=card_from_letters('Q','c');
	  print_card(c);
     printf("\n");
     for (unsigned j=0; j<52; j++) {
       c=card_from_num(j);
       print_card(c);
       if (j==12||j==25||j==38||j==51){
	 printf("\n");
       }
       
     }
     printf("end of main \n");
     return 0;
}
