/*
Include:
   #include <stdio.h>
   #include <stdlib.h>  - imports void srand(), use for random number generation
   #include <time.h>    - base random number on time because it's constantly changing

define main function as void

declare int variable: user_option
call menu()
assign user_option to returned value from menu()

declare constant int: MAX_VALUE = 100
declare time_t
declare boolean: q
declare int variable: max_num (default value 10), random
declare int or string (char str[]) variable: user_num
assign random using srand() or rand()

enter do-while: user_option is 1 or 2   (3 should end program)

   create if statements for user_option if either 1,2, or 3

   user_option == 1
      ask user to enter number between 1 and max_num
      assign user_num with scanf()
      enter while statement, while user_num does not equal random
         if user_num equals q
            break while statement
         else if user_num less than random
            print: Too low.\n Guess Again:
         else
            print: Too high.\n Guess Again:
         reassign user_num with scanf()
      if user_num is not q
         print: Correct!
      else
         call menu()
         reassign user_option

   user_option == 2
      print: The max value you can set to is MAX_VALUE
      reassign max_num with scanf()
      while statement: max_num is negative or above MAX_VALUE
         print: invalid update. Max value must be between 1 and MAX_VALUE.
         print: Reenter max value:
         reassign max_num with scanf()
      call menu()
      reassign user_option


   user_option == 3
      print: Thank you for playing!

end of main


define menu function as int
declare int user_input
print:
   Menu
   ================================
   Press 1 to play a game
   Press 2 to change the max number
   Press 3 to quit
   \n

assign user_input with scanf()
while user_input is not 1,2, or 3
   print: invalid option.
   reassign user_input() with scanf()

return user_input



define is_q function as boolean, param: int num
   if num is not less than or equal to zero or greater than zero
      not a number -> most likely q
      return true
   else 
      return false

*/

/* start of code */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int menu(); // declare function

void main()
{
   int user_option;
   user_option = menu();

   FILE *out;
   FILE *exist;
   const int MAX_VALUE = 100;
   time_t t;
   int max_num = 10, random, temp_int;
   char user_num[5];

   srand((unsigned)time(&t));
   random = (rand() % max_num) + 1;

   if (exist = fopen("maxNumber.dat", "w")) //check if file exists
   {
      fscanf(exist, "%d", max_num); //assign max_num with current value
     // printf("File exists.");
   }
   else //else create file, assign default num
   {
      out = fopen("maxNumber.dat", "w");
      fprintf(out, "%d", max_num);
   }

   do
   {
      if (user_option == 1)
      {
         printf("Press q to quit game\n");
         printf("Enter number between 1 - %d\n", max_num);
         scanf("%s", &user_num);

         do
         {
            if (user_num[0] == 'q')
               break;

            temp_int = strtod(user_num, NULL);

            if (temp_int > random)
               printf("Too High. ");
            else //(temp_int < random)
               printf("Too Low. ");

            printf("Guess Again: ");
            scanf("%s", user_num);

            temp_int = strtod(user_num, NULL);

         } while (temp_int != random);

         if (temp_int == random)
            printf("Congrats! The random number was: %d\n", random);
         random = (rand() % max_num) + 1;
         user_option = menu();
      }

      else if (user_option == 2)
      {
         printf("The max value you can set to is %d.\nEnter new max value: ", MAX_VALUE);
         scanf("%d", &max_num);

         while (max_num < 1 || max_num > MAX_VALUE)
         {
            printf("Invalid Update. \nReenter max value: ");
            scanf("%d", &max_num);
         }

         out = fopen("maxNumber.dat", "w");  //overwrites file
         fprintf(out, "%d", max_num);        //update with new user max number

         printf("Max value changed to %d\n\n", max_num);    //validation
         user_option = menu();
      }

      else
      {
         printf("Thanks for playing!");
         break;
      }
   } while (user_option == 1 || user_option == 2 || user_option == 3);

   fclose(out);
   fclose(exist);
}

int menu()
{
   int user_input;

   printf("\nMenu\nPress 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
   scanf("%d", &user_input);

   while (user_input != 1 && user_input != 2 && user_input != 3)
   {
      printf("Invalid Option. Pick option 1, 2, or 3.\n");
      scanf("%d", &user_input);
   }

   return user_input;
}
