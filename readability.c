#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // ask the user for sm texts
    string text = get_string("text: ");

    // cout the numbers of letters
    int l = count_letters(text);

    // cout the numbers of words
    int w = count_words(text);

    // cout the numbers of sentences
    int s = count_sentences(text);

    // compute the liau index
    float calculation = (0.0588 * l / w * 100) - (0.296 * s / w * 100) - 15.8;
    int index = round(calculation);

    // print thr grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // or if ((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i<= 'Z']))
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    // to see a line finished, check every single line and if(? . !) at the end the lines over.
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
