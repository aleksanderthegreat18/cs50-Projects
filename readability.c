#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string reading = get_string("Text: ");
    int length = strlen(reading);
    int i;
    int counter = 0;
    int oneLetter;
    int length2 = length;
    float words = 0;

    for (i = 0; i <= length; i++)
    {
        oneLetter = reading[i];
        //printf("%d\n",oneLetter);
        if (oneLetter == 63)
        {
            counter++;
            length2--;
        }
        else if (oneLetter == 33)
        {
            counter++;
            length2--;
        }
        else if (oneLetter == 46)
        {
            counter++;
            length2--;
        }
        else if (oneLetter == 32)
        {
            length2--;
            words++;
        }
        else if (oneLetter == 39)
        {
            length2--;
        }
        else if (oneLetter == 44)
        {
            length2--;
        }
        else if (oneLetter == 34)
        {
            length2--;
        }
        else if (oneLetter == 58)
        {
            length2--;
        }
        else if (oneLetter == 38)
        {
            length2--;
        }
        else if (oneLetter == 39)
        {
            length2--;
        }
        else if (oneLetter == 40)
        {
            length2--;
        }
        else if (oneLetter == 41)
        {
            length2--;
        }
        else if (oneLetter == 59)
        {
            length2--;
        }

    }

    if (length2 >= 1)
    {
        words++;
    }
    
    float wordform = 100 / words;
    float L = length2 * wordform;
    float S = counter * wordform;
    float form = 0.0588 * L - 0.296 * S - 15.8;
    //printf("%d letter(s)\n", length2);
    //printf("%f word(s)\n", words);
    //printf("%d sentence(s)\n", counter);
    //printf("%.2f\n", wordform);
    //printf("%.2f\n", L);
    //printf("%.2f\n", S);
    if (form >= 15.5)
    {
        printf("Grade 16+\n");
    }
    else if (form <= 1.49)
    {
        
        printf("Before Grade 1\n");
    
    }
    else
    {
        printf("Grade %.0f\n", round(form));
    }
}
