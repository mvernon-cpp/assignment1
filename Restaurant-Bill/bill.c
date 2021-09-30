/*
Include: 
   #include <stdio.h>
   #include <stdlib.h>  - imports void srand(), use for random number generation
   #include <time.h>    - base random number on time because it's constantly changing

define main function as int

declare time_t
decalre & assign array variables: meal (char *), cost (float)
declare float variables: tax, tip (represents percentage), tax_total, tip_total, meal_total
declare int varaible: random (represents index for meal & cost)
assign tax & tip with user input: scanf()

assign random to use srand() or rand() to pick number 0-3, index to pick which meal to use

calculate tax_amount & tip_amount
calculate meal_total

print:
   Random meal chosen with price
   tax_amount
   tip_amount
   meal_total

return 0;
*/

/* start of code */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   time_t t;
   char *meal[] = {"Salad", "Soup", "Sandwich", "Pizza"};
   float cost[] = {9.95, 4.55, 13.25, 22.35};
   float tax, tip, tax_total, tip_total, meal_total;
   int random;

   srand((unsigned)time(&t));
   random = rand() % 4;

   printf("Enter tax percent: ");
   scanf("%f", &tax);
   printf("Enter tip percent: ");
   scanf("%f", &tip);

   tax_total = (tax / 100.0) * cost[random];
   tip_total = (tip / 100.0) * cost[random];
   meal_total = cost[random] + tax_total + tip_total;

   printf("\nBILL\n===============\n");
   printf("%s: $%.2f\nTax: $%.2f\ntip: $%.2f\nTotal: $%.2f\n\n", meal[random], cost[random], tax_total, tip_total, meal_total);

   return 0;
}