#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char rotate(char c, int n);

bool only_digits(string key);

int words[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

string plaintext;

int main(int argc, string argv[1])
{
    string ciphertext;
    // program runs with just 1 command-line arg
    if (argc > 2 || NULL)
    {
        printf("key\n");
        return 1;
    }
    else if (argc == 2)
    {
        return 0;
    }

    // also add that it should be positive int and no words
    bool only_digits(string arg[1])
    {
        if (true)
        {
        return 0;
        }
        else
        {
            printf("key\n");
            return 1;
        }
    }
 // convert arg[1] from a 'string' to an int
        int key = int atoi(arg[1]);

    // prompt the user for plaintext
    plaintext = get_string("plaintext: ");
    printf("%S", plaintext);

    // for each char in the plaintext:
    for (int i = 0; i != '\0'; i++)
    {
        // rotate the char if it's a letter
        ciphertext = rotate(plaintext[i]);
        //print the return value from rotate fuction
        printf("ciphertext:%c", ciphertext);
    }

}

// every char in argv[1] is a digit. And between 0 to 9
bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]) && i >= 0 || i <= 9)
        {
                return true;
        }
        else
        {
            return false;
        }
    }
}

char rotate(char, int)
{
    char ciphertext;
   for(int i =0; i<strlen(key); i++)
{
    //wrap around
    if (plaintext[i]>25)
    {
    int n;
    n = i % 25;
    plaintext[i] = n;
   }
     if (isupper(plaintext[i]))
        {
            plaintext[i]=plaintext[i-65];
            ciphertext[i] = plaintext[word[i] + key];
            ciphertext = ciphertex[i + 65];

        //brif printf('%c',(((plaintext[i]-65) + key) %25) +65)
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i]=plaintext[i-97];
            ciphertext[i] = plaintext[word[i] + key];
            ciphertext = ciphertext[i + 97];
        }
        else
        {
            return plaintext[i];
        }

   }
   return ciphertext;
}
