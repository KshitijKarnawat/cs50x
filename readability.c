#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);
int grade(int, int, int);

int main(void)
{
    // Takes the text from user
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index = grade(letters, words, sentences);

    // Prints the Grade of the text
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }
    }
}

// Count letters
int count_letters(string text)
{
    int len = strlen(text), count = 0;

    for (int i = 0; i < len; i++)
    {
        // Counts letters and excludes special characters and spaces
        if (('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}

// Count words
int count_words(string text)
{
    int len = strlen(text), count = 1;

    for (int i = 0; i < len; i++)
    {
        // 32 == Space in ascii
        if (text[i] == 32)
        {
            count++;
        }
    }
    return count;
}

// Count number of sentences
int count_sentences(string text)
{
    int len = strlen(text), count = 0;

    for (int i = 0; i < len; i++)
    {
        // Sentences end at '.', '!', '?'
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

// Calculate the Grade of the text
int grade(int letters, int words, int sentences)
{
    float L = 100.0 / words * letters;
    float S = 100.0 / words * sentences;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}