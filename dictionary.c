#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
unsigned int count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
     //hash the word in order to obtain a hash value
     unsigned int i = hash(word);

     //check each linked list. treverse the linked list at the corresponding index.
     for (node *c = table[i]; c != NULL; c = c->next)
        {
            //consider upper case and lower case as same.by strcasecmp insstead of strcmp.
            if (strcasecmp( word , c->word ) == 0)
            {
                return true;
            }
            //does it know to go to c->next if the above if condition aint applied?
        }

     return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int counter = 0;
    unsigned int sum;
    // TODO: Improve this hash function
    for (int i = 0; i<strlen(word); i++)
    {
        int index = toupper(word[i]) - 'A';

        if(index<0 || index > N-1)
         {
             return 1;
         }
         counter = counter + index;
    }
         sum = counter % N;
         return sum;

}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open dictionary file
    count = 0;
    FILE *source  = fopen(dictionary, "r");

    if(source == NULL)
    {
        printf("could not open %s\n", dictionary);
        return 2;
    }

     //create a string to put the dictionary word u are trying to read by fscanf.
     char word[LENGTH + 1];

     //read strings from a file one at a time
     while (fscanf(source, "%s" ,word) != EOF)
     {
     //create a new node for each word
    node *m = malloc(sizeof(node));
     {
        if (m == NULL)
        {
            return false;
        }
     }

     //copying the dictionary word into the node i'v created to make a linked list at the found table[].
     strcpy(m->word , word);

     //hash word to obtain a hash value.
     unsigned int i = hash(word);

     //insert node into hash table at the location
     m->next = table[i];
     table[i] = m;
     count ++;
     size();
     }

    //close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
//either count each word as you load it into the dictionary. Return that count when size is called.
if(count > 0)
{
    return count;
}
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int i;
    for ( i = 0; i < N; i++)
    {
        node *j = table[i];

        while(j != NULL)
        {
            node *tmp = j;
            j = j->next;
            free(tmp);
        }
}
  return true;
}

