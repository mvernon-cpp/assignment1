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