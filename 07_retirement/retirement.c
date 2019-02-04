#include<stdio.h>
#include<stdlib.h>
// retirement information
struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

// retirement function

void retirement (int startAge, double initial, retire_info working, retire_info retired){
  double balance=initial;
  for (int age=startAge; age< (startAge+working.months+retired.months); age++){
  printf("Age  %d month %2d you have $%.2lf\n", age/12,age % 12, balance);
  if (age<startAge+working.months){
  balance=balance*(1+working.rate_of_return)+working.contribution;
  }
  else {
  balance=balance*(1+retired.rate_of_return)+retired.contribution;
  }
  }
  }
int main (void) {
 retire_info working;
 working.months=489;
  working.contribution=1000.00;
working.rate_of_return=0.045/12.0;
 retire_info retired;
 retired.months=384;
  retired.contribution=-4000.00;
retired.rate_of_return=0.01/12.0;
 int startAge=327;
 double initial= 21345.00;
 retirement (startAge,initial, working, retired);
 
 return 0;
}
