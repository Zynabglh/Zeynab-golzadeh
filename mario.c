#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int height, row, spacing, column;
//height is between 1-8
do
{
    height = get_int("height: ");
}
while(height<1 || height>8);
//total number of rows
      for(row = 0; row<height; row++)
      {
//putting proper distance nested within the number of rows
        for(spacing=0; spacing<height-row-1; spacing++)
        {
            printf(" ");
        }
//to relate number of c0lumns with rows meaning it will make as many columns as rows not more
            for( column=0; column<= row; column++)
            {
              // this(#) is just the symbole being used to create the "pyramid"
              printf("#");
            }
            // creats new line up to the parameters provided
            printf("\n");
      }
}
