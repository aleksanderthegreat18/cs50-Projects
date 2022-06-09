#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(int argc, char *argv[])  
{
    int i; 
    int oneLetter;
    int counter = 0;
    int length;
    int letters[26];
    int allOnes = 1;
    char *ciphertext;
    char *cipherstring;
    string plaintext;
    int key;
    char output[300] = "";
   
    int length2;
   
    if (argc == 1) 
    {
        return 1;
       
    }
   
    length = strlen(argv[1]);
   
    cipherstring = argv[1];
    for (i = 0; i <= 25; i++) 
    {
        letters[i] = 0;
    }
   
    if (argc == 2) 
    {
       
        if (length == 26)
        {
            
        
        
            for (i = 0; i <= length; i++)
            {
                oneLetter = argv[1][i];
                if ((oneLetter >= 65 && oneLetter <= 95)  || (oneLetter >= 97 && oneLetter <= 122))
                {
                    counter++;
                    if (oneLetter >= 65 && oneLetter <= 95)
                    {
                        oneLetter = oneLetter + 32;
                        //printf("Uppercase, %c\n", oneLetter);
                    }
                    letters[oneLetter - 97 ] = letters[oneLetter - 97 ] + 1;
                }
            }
            for (i = 0; i <= 25; i++) 
            {
                if (letters[i] == 1 && allOnes == 1)
                {
                
                    allOnes = 1;
                
                }
                else
                {
                    allOnes = 0;
                }
                //printf("%c: %d\n",97+i,letters[i]);
                //printf("%d\n", allOnes);
            }
        
            if (counter == 26 && allOnes == 1)
            {
                plaintext = get_string("plaintext: ");
                //printf("%s***\n", plaintext);
                length2 = strlen(plaintext);
                //printf("lenght2: %d\n",length2);
                for (i = 0; cipherstring[i]; i++)
                {
                    cipherstring[i] = tolower(cipherstring[i]);
                }
            
                for (i = 0; i <= length2 - 1; i++)
                {
                    key = cipherstring[i];
                    oneLetter = plaintext[i];
                    if (oneLetter >= 65 && oneLetter <= 95)
                    {
                        //printf("%c cipher equivalent: %c\n", oneLetter,cipherstring[oneLetter - 65] - 32);
                        output[i] = cipherstring[oneLetter - 65] - 32;
                        //strcat(output,&cipherstring[oneLetter - 65] - 32);
                    
                    }
                    else if (oneLetter >= 97 && oneLetter <= 122)
                    {
                    
                        //printf("%c cipher equivalent: %c\n", oneLetter,cipherstring[oneLetter - 97]);
                        output[i] = cipherstring[oneLetter - 97];
                        //strcat(output,&cipherstring[oneLetter - 97]);
                    }
                    else
                    {
                        //printf("%c\n", oneLetter);
                        output[i] = oneLetter;
                        //strcat(output,&oneLetterc);
                    }
                }
                output[i + 1] = '\0';
                printf("ciphertext: %s\n", output);
            
            }
            else
            {
                return 1;
            }
        }
        else
        {
        
            return 1;
        }
   
   
    

    
    }
}   


