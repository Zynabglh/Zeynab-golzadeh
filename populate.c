#include<cs50.h>
#include<stdio.h>

int main(void)
{
   int start, end , years = 0;
   //prompt for start size
   do
   {
    printf ("Enter starting population size (minimum 9): ");
    start=get_int("start size: ");
    printf("%i",start);
   }
   while (start <= 9);

   // promp for end size
   do
   {
    printf("Enter ending size(minimum %i):", start);
    end = get_int("end size: ");
    printf("%i", end);
   }
   while (end < start);

   //calculate the nnumber of years untill we reach threshold
   while (start < end)
   {
    start = start + start/3 - start/4;
    years++;
   }
   printf("years= %i\n", years);
   return 0;

}