#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("./recover image\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("couldnt open %s\n", argv[1]);
        return 2;
    }

    int counter = 0;
    BYTE buffer[512];
    // Char for the name of the jpg.
    char *filename = malloc(8 * sizeof(char));
    FILE *output = NULL;

    while (fread(buffer, sizeof(BYTE), 512, input) == 512)
    {
        // for irretating thru the buffer.
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if one is alreay close it. id aint means its the first jpg.
            // since the counter is set to 0 we once pas this if bc counter is 0 and afer that 1 time (first jpg) this if applies.
            if (counter != 0)
            {
                fclose(output);
            }
            // sprintf is for making the file name placed in fopen.
            sprintf(filename, "%.03i.jpg", counter);
            // putting fopen last bc first need to make tthe file name then open it. opeing anew file with that file name.
            output = fopen(filename, "w");
            fwrite(buffer, sizeof(BYTE), 512, output);
            if (output == NULL)
            {
                // bc aint there a memory for it bc if were finished while loop itself would close and return 0;
                fclose(input);
                printf("couldnt create %s\n ", filename);
                return 3;
            }
            counter++;
        }
        else if (counter > 0)
        {
            // we are repeating fwite bc it runs the fwrte in the if loop only if the new pattern
            // is found and we need the function to write untill we find another then start again
            // which that starting again is in the loop
            fwrite(buffer, sizeof(BYTE), 512, output);
        }
    }
    fclose(input);
    free(filename);
    // if there is any file open close it.its false bc wont fine any anymore and need to close it here bc wont go in the loop.
    fclose(output);
    return 0;
}

