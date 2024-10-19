#include<cs50.h>
#include<stdio.h>

int main(void)

{
   int start, end , years = 0;
   //prompt for start size
   do
   {
    printf("enter starting population(minimum 9): ");
    scanf("%d",&start);
    }
   while (start <= 9);

   // prompt for end size
   do
   {
    printf("enter ending size(minimum %d):", start);
    scanf("%d",&end);
    }
   while (end < start);

   //calculate the nnumber of years untill we reach threshold
   while (start < end)
   {
    start = start + start/3 - start/4;
    years++;
   }

   printf(years= "%d\n", years);
   return 0;

}