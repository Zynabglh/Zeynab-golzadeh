#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
void print_bulb(int bit);

int main(void)
{
   string message = get_string("message: ");

// loop thru each char in message
for(int i = 0; message[i]!='\0'; i++)
{
 int dec = message[i];
 int binary[8] = {};

int j = 0;
while(dec>0)
{
    binary[j]= dec % 2;
    dec = dec/2;
    j++;
}
for(int k= BITS_IN_BYTE-1; k>=0; k--)
{
print_bulb(binary[k]);
}
printf("\n");
 }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}