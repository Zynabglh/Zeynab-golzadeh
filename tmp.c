#include <cs50.h>
#include <stdio.h>

int main(void)
{
    void swap(int x , int y );
    int x = 1;
    int y = 2;
    printf("x is %i, y is %i\n", x, y);
    swap(x,y);
     printf("x is %i, y is %i\n", x, y);
}
void swap(int x,int y)
{
      printf("x is %i, y is %i\n", x, y);
     int tmp = x;
     x = y;
     y = tmp;
     printf("x is %i, y is %i\n", x, y);
}