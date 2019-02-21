#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  if (c.value < 2 || c.value >14){
    //    printf("this is not an acceptable card value");
    assert (c.value>=2 && c.value<=14);
      }
  if (c.suit < SPADES || c.suit >CLUBS){
    //    printf("this is not an acceptable card suit");
    assert (c.suit>=SPADES && c.suit<=CLUBS);
      }
  }

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case 0: return "STRAIGHT_FLUSH"; break;
  case 1:  return "FOUR_OF_A_KIND"; break; 
  case 2:  return "FULL_HOUSE"; break; 
  case 3: return "FLUSH"; break;
  case 4: return "STRAIGHT"; break;
  case 5: return "THREE_OF_A_KIND"; break;
  case 6: return "TWO_PAIR"; break;
  case 7: return "PAIR"; break;
  case 8: return "NOTHING"; break;
   }
  return "";
}

char value_letter(card_t c) {
  switch(c.value){
  case 2: return 50; break;
  case 3: return 51; break;
  case 4: return 52; break;
  case 5: return 53; break;
  case 6: return 54; break;
  case 7: return 55; break;
  case 8: return 56; break;
  case 9: return 57; break;
  case 10: return 48; break;
  case 11: return 74; break;
  case 12: return 81; break;
  case 13: return 75; break;
  case 14: return 65; break;    
}
    return 'x';
}

char suit_letter(card_t c) {
  switch(c.suit){
  case 0: return 's' ; break;
  case 1: return 'h' ; break;
  case 2: return 'd' ; break;
  case 3: return 'c' ; break;
  case 4: return '4'; break;    
  }
    return 'x';
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  int x=value_let;
  int y=suit_let;
  switch(x){
  case 48: temp.value=10;break;
  case 50: temp.value=2;break;
  case 51: temp.value=3;break;    
  case 52: temp.value=4;break;
  case 53: temp.value=5;break;
  case 54: temp.value=6;break;
  case 55: temp.value=7;break;
  case 56: temp.value=8;break;
  case 57: temp.value=9;break;
  case 65: temp.value=14;break;    
  case 74: temp.value=11;break;
  case 75: temp.value=13;break;
  case 81: temp.value=12;break;
  default:  printf("invalid card letter, cards_from_letters failed \n ");
      exit(EXIT_FAILURE);
  }
  switch (y){
  case 99: temp.suit=3;break;
  case 100: temp.suit=2;break;
  case 104: temp.suit=1;break;       
  case 115: temp.suit=0;break;
  default:  printf("invalid card suit, cards_from_letters failed \n ");
      exit(EXIT_FAILURE);
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value=c%13+2;
  temp.suit=(c/13)%4;
  if (c>51){
    printf("invalid: numbers should be between 0 and 51 for a 52-card deck ");
      exit(EXIT_FAILURE);
  }
  return temp;
}
